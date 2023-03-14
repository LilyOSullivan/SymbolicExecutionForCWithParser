:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(function_info).

:- ['expressions'].
:- ['statement_handler'].
:- ['utils'].

%% sub_atom/5 is used in creating function_info variables.
%% It strips the LC_/UC_ from the function name, while retaining it as an atom.
:- import sub_atom/5 from iso_light.
:- import atom_codes/2 from iso_light.

%% Global values:
%%  test_id (Number, value:1): This is an Id used to identify test cases generated
%%  tests (List, value:[]): This list holds the names of the generated test cases
%%      Eg: ["test_1", "test_2", "test_3"...]

%% Run regression tests
regression_tests :-
    Filename_without_extension = "regression_source",
    Path = "../LexYacc/regression_tests",
    Path_to_parser = "../LexYacc",

    % Run the preprocessor before the parser
    sprintf(Run_preprocessor_command, "cd %s && cl /EP /P %s.c", [Path, Filename_without_extension]),
    sh(Run_preprocessor_command),
    sprintf(Path_to_i_file, "%s/%s.i",[Path, Filename_without_extension]),
    (exists(Path_to_i_file) ->
        true
    ;
        (
            writeln("Failed to preprocess with CL"),
            halt
        )
    ),

    % Run the parser
    sprintf(Run_parser_command, "cd %s && .\\LilyParser.exe .//regression_tests  %s .//regression_tests", [Path_to_parser, Filename_without_extension]),
    sh(Run_parser_command),
    sprintf(Path_to_pl_file, "%s/%s.pl", [Path, Filename_without_extension]),
    (exists(Path_to_pl_file) ->
        true
    ;
        (
            writeln("Failed to parse"),
            halt
        )
    ),

    concat_string([Path, "/", Filename_without_extension, ".pl"], Prolog_file),
    read_prolog_file(Prolog_file, Result),
    find_function_name(Result, Function_name),

    % Run symbolic execution
    main(Filename_without_extension, Function_name, Path),
    % Compile test cases
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Function_name, "_tests_main.c"], Main_filename),

    % Compile the main test file
    sprintf(Compile_string, "cd %s && x86_64-w64-mingw32-gcc -o %s.exe %s -lcunit", [Path_to_test_directory, Function_name, Main_filename]),
    (sh(Compile_string) ->
        true
    ;
        (
            printf("Failed to compile test cases: %s", [Function_name]),
            halt
        )
    ),

    % Run test cases
    sprintf(Run_string, "cd %s && %s.exe", [Path_to_test_directory, Function_name]),
    (sh(Run_string) ->
        true
    ;
        (
            printf("Test cases encountered failure: %s", [Function_name]),
            halt
        )
    ),
    fail.
regression_tests.

%% A shortcut predicate to main/3 outputting to the Prolog directory
%% Useful for development. This is not called in code, only by a developer
%% regression_main/1 is called during the regression tests
regression_main(Function_name) :-
    atom(Function_name),
    atom_codes(Function_name, Codes),
    string_codes(Filename_string, Codes),
    main(Filename_string, Function_name, "./").

%% A shortcut predicate to main/3 outputting to the Prolog directory
%% Useful for development. This is not called in code, only by a developer
%% main/1 is used during development of the symbolic execution engine
main(Function_name) :-
    main("sign", Function_name, "./").

%% The entrypoint to the program
%% Filename_without_extension: The name of the file without the .pl extension
%%                             This should be a string.
%%                 Eg: "sign"
%% Function_name: The entry function to be tested. This should be an atom.
%%                 Eg: get_sign
%% Path_to_C_file: The folder-path to the C file to be symbolically executed.
%%                          This should be a string.
%%                 Eg: "C:\\Users\\user\\Desktop"
main(Filename_without_extension, Function_name, Path_to_C_file) :-
    string(Filename_without_extension),
    atom(Function_name),
    string(Path_to_C_file),
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(33, 126)),
    ptc_solver__type(boolean_int, integer, range_bounds(0, 1)),
    % 33-126 are the printable ASCII characters
    % https://www.ascii-code.com
    concat_string([Path_to_C_file, "/", Filename_without_extension, ".pl"], Prolog_file),
    read_prolog_file(Prolog_file, Terms),
    declare_functions(Terms),
    process_global_variables(Terms),
    once find_function_information(Terms, Function_name, Function_info),
    utils__get_clean_function_info(Function_info, _, Params, Body, Return_type),
    setup_test_driver(Function_name, Path_to_C_file),
    function_handler(Filename_without_extension, Function_name, Body, Params, Return_type). % From Statement_handler.pl

%% Setup for the test-driver
%% Parameters:
%%  Function_name: The entry function to be tested. This should be an atom.
%%                 Eg: get_sign
%%  Path_to_C_file: The folder-path to the C file to be symbolically executed.
setup_test_driver(Function_name,Path_to_C_file) :-
    get_flag(unix_time, Unix_time),
    % Format: 24Hours_Minutes_Seconds__days_months_year
    % Eg: 14_34_18__03_02_23
    local_time_string(Unix_time,"%H_%M_%S__%d_%m_%y", Current_date_as_string),
    concat_string([Function_name, "_tests_", Current_date_as_string], Folder_name),
    concat_string([Path_to_C_file, "/", Folder_name, "/"], Path_to_test_directory),

    % Foldername used for the generated test-cases
    setval(test_folder_path, Path_to_test_directory),

    % The initial Id used to identify test cases generated. Used in test_generation.pl
    setval(test_id, 1),

    % A list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl
    % when generating the '_main' cunit .c file
    setval(tests, []).

%% Reads the parser-result prolog file, and returns its' contents
%% This is used in place of the compile predicate. The compile predicate
%% strips variable names when compiling.
%% Parameters:
%%  Relative_path: The path to the prolog file to be read
%%  Result: The contents of the prolog file
read_prolog_file(Relative_path, Result) :-
    open(Relative_path, read, Stream),
    % Asserting breaks the variable links.
    % Return the content directly instead.
    read_term(Stream, Parsed_terms, []),
    close(Stream),
    Parsed_terms = parsed(Result).

%% Initialise global variables
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
process_global_variables([]).
process_global_variables([Term | More_terms]) :-
    % Statements 999 is a dummy variable created by the parser
    (Term = global_variables(Statements, _), Statements \== 999 ->
        statement_handler(Statements, return(_, _)) % From Statement_handler.pl
    ;
        true
    ),
    process_global_variables(More_terms).

%% Finds the function definition for a desired function
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  Function_name: The name of the function to be found
%%  Params: The parameters of the function to be found
%%  Body: The body of the function to be found
%%  Return_type: The return type of the function to be found
find_function_information([function_definition(Function_info, _, _ , _) | More_terms], Function_name, Return_function_info) :-
    function_info__get_name(Function_info, Current_function_name),
    (Current_function_name == Function_name ->
        Return_function_info = Function_info,
        !
    ;
        find_function_information(More_terms, Function_name, Return_function_info)
    ).
find_function_information([_ | More_terms], Function_name, Return_function_info) :-
    find_function_information(More_terms, Function_name, Return_function_info).
find_function_information([], _, _) :- !, false.

%% Finds the name of a function from the parser-result prolog file
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  Function_name: The name of the function to be found
find_function_name([function_definition(Function_name, _, _, _) | _], Function_name).
find_function_name([_ | More_terms], Function_name) :-
    find_function_name(More_terms, Function_name).
find_function_name([], _) :- false.


declare_functions([]).
declare_functions([function_definition(Function_info, Params, Body, Return_type) | More_terms]) :-
    get_var_info(Function_info, name, Function_name_as_atom),
    % Strip 'LC_' or 'UC_' from the function name
    sub_atom(Function_name_as_atom, 3, _, 0, Stripped_function_name),
    Function_def = function_definition(Stripped_function_name, Params, Body, Return_type),
    function_info__create(Function_def, Function_info),
    declare_functions(More_terms),
    !.
declare_functions([_ | More_terms]) :-
    declare_functions(More_terms).
