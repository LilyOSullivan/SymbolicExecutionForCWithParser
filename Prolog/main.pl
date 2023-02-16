:- lib(ptc_solver).

:- ['utils'].
:- use_module(c_var).
:- ['expressions'].
:- ['statement_handler'].

:- dynamic var_names/2.

%% Global values:
%%  test_id (Number, value:1): This is an Id used to identify test cases generated
%%  tests (List, value:[]): This list holds the names of the generated test cases
%%      Eg: ["test_1","test_2","test_3"...]

%% Run regression tests
regression_tests :-
    Filename_without_extension = "regression_source",
    Path = "../LexYacc/regression_tests",
    Path_to_parser = "../LexYacc",

    % Run the preprocessor before the parser
    sprintf(Run_preprocessor_command,"cd %s && cl /EP /P %s.c",[Path,Filename_without_extension]),
    sh(Run_preprocessor_command),
    sprintf(Path_to_i_file,"%s/%s.i",[Path,Filename_without_extension]),
    (exists(Path_to_i_file) ->
        true
    ;
        (
            writeln("Failed to preprocess with CL"),
            halt
        )
    ),

    % Run the parser
    sprintf(Run_parser_command,"cd %s && .\\LilyParser.exe .//regression_tests  %s .//regression_tests",[Path_to_parser,Filename_without_extension]),
    sh(Run_parser_command),
    sprintf(Path_to_pl_file,"%s/%s.pl",[Path,Filename_without_extension]),
    (exists(Path_to_pl_file) ->
        true
    ;
        (
            writeln("Failed to parse"),
            halt
        )
    ),

    concat_string([Path, "/", Filename_without_extension, ".pl"], Prolog_file),
    compile(Prolog_file),
    function_definition(Function_name, _, _, _),

    % Run symbolic execution
    main(Filename_without_extension, Function_name, Path),
    % Compile test cases
    getval(test_folder_path,Path_to_test_directory),
    concat_string([Function_name,"_tests_main.c"], Main_filename),

    % Compile the main test file
    sprintf(Compile_string,"cd %s && x86_64-w64-mingw32-gcc -o %s.exe %s -lcunit", [Path_to_test_directory, Function_name, Main_filename]),
    (sh(Compile_string) ->
        true
    ;
        (
            printf("Failed to compile test cases: %s",[Function_name]),
            halt
        )
    ),

    % Run test cases
    sprintf(Run_string,"cd %s && %s.exe", [Path_to_test_directory, Function_name]),
    (sh(Run_string) ->
        true
    ;
        (
            printf("Test cases encountered failure: %s",[Function_name]),
            halt
        )
    ),
    fail.
regression_tests.


%% A shortcut predicate to main/3 outputting to the Prolog directory
%% Useful for development. This is not called in code, only by a developer
main(Filename_without_extension,Function_name) :-
    main(Filename_without_extension, Function_name, "./").

%% The entrypoint to the program
%% Filename_without_extension: The name of the file without the .pl extension
%%                             This should be a string.
%%                 Eg: "sign"
%% Function_name: The entry function to be tested. This should be an atom.
%%                 Eg: get_sign
%% Path_to_C_file: The path to the C file to be symbolically executed.
%%                          This should be a string.
%%                 Eg: "C:\\Users\\user\\Desktop"
main(Filename_without_extension, Function_name,Path_to_C_file) :-
    string(Filename_without_extension),
    atom(Function_name),
    string(Path_to_C_file),

    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(33, 126)),
    % 33-126 are the printable ASCII characters
    % https://www.ascii-code.com

    concat_string([Path_to_C_file, "/", Filename_without_extension, ".pl"], Prolog_file),

    % % Read the prolog file. This is used in place of the compile predicate
    % % The compile predicate strips variable names when compiling
    % open(Prolog_file, read, Stream),
    % repeat, % Leaves continuous choice points for the fail. Cut is used to exit the loop
    read_prolog_file(Prolog_file),
    find_function_information(Function_name, Params, Body, Return_type),
    setup_for_function(Filename_without_extension, Function_name,Path_to_C_file),
    process_global_variables,
    function_handler(Filename_without_extension, Function_name, Body, Params, Return_type). % From Statement_handler.pl

% global_variables([
%     declaration(int, [LC_y_0]),
%     assignment(LC_y_0 , 5) ], void).


% IDEA: Name predicate: setup_test_driver
% QUESTION: How would id's work across multiple functions?
%           Possibly a merge-term of the function name per setval?
%% Setup used for each function by the test-driver
setup_for_function(Filename, Function_name,Path_to_C_file) :-
    concat_string([Path_to_C_file, "/", Filename, ".names"], Names_filename),
    compile(Names_filename),
    get_flag(unix_time, Unix_time),

    % Format: days/months/year__24Hours_Minutes_Seconds
    % Eg: 03_02_23__14_34_18
    local_time_string(Unix_time,"%d_%m_%y__%H_%M_%S", Current_date_as_string),
    concat_string([Function_name, "_tests_", Current_date_as_string], Folder_name),
    concat_string([Path_to_C_file, "/", Folder_name, "/"], Path_to_test_directory),

    % Foldername used for the generated test-cases
    setval(test_folder_path, Path_to_test_directory),

    % The initial Id used to identify test cases generated. Used in test_generation.pl
    setval(test_id, 1),

    % A list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl
    % when generating the '_main' cunit .c file
    setval(tests, []).

read_prolog_file(Relative_path) :-
    read_terms_from_file(Relative_path, Result),
    asserta(Result).

process_global_variables :-
    parsed(Terms),
    initialise_globals(Terms).

initialise_globals([]).
initialise_globals([H|T]) :-
    (H = global_variables(Statements, _) ->
        statement_handler(Statements,_) % From Statement_handler.pl
    ;
        true
    ),
    initialise_globals(T).

find_function_information(Function_name, Params, Body, Return_type) :-
    parsed(Terms),
    find_function(Terms, Function_name, Params, Body, Return_type),
    !.

find_function([],_,_,_,_).
find_function([Term|More_terms], Function_name, Params, Body, Return_type) :-
    (Term = function_definition(Function_name, Params, Body, Return_type) ->
        true
    ;
        find_function(More_terms, Function_name, Params, Body, Return_type)
    ).

read_terms_from_file(Filename, Result) :-
    open(Filename, read, Stream),
    read_terms_from_stream(Stream, Result),
    close(Stream).

read_terms_from_stream(Stream, Term) :-
    read_term(Stream, Term, []).
