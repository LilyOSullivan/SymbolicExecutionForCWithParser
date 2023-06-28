:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(function_info).

:- ['declaration'].
:- ['expressions'].
:- ['statement_handler'].
:- ['utils'].

%% sub_atom/5 is used in creating function_info variables.
%% It strips the LC_/UC_ from the function name, while retaining it as an atom.
:- import sub_atom/5 from iso_light.

%$ Used in regression_main/1 to convert an atom to a string
:- import atom_codes/2 from iso_light.

%% Global values:
%%  test_id (Number, value:1): This is an Id used to identify test cases generated
%%  tests (List, value:[]): This list holds the names of the generated test cases
%%      Eg: ["test_1", "test_2", "test_3"...]

%% A shortcut predicate to main/3 outputting to the Prolog directory
%% Useful for development. This is not called in code,
%% only by the regression testing tool.
regression_main(Function_name) :-
    atom(Function_name),
    atom_codes(Function_name, Codes),
    string_codes(Filename_string, Codes),
    main(Filename_string, Function_name, "./", false).

%% A shortcut predicate to main/3 outputting to the Prolog directory
%% Useful for development. This is not called in code, only by a developer
%% main/1 is used during development of the test-driver
main(Function_name) :-
    main("sign", Function_name, "./", false).

%% The entrypoint to the program
%% Filename_without_extension: The name of the file without the .pl extension
%%                             This should be a string.
%%                 Eg: "sign"
%% Function_name: The entry function to be tested. This should be an atom.
%%                 Eg: get_sign
%% Path_to_C_file: The folder-path to the C file to be symbolically executed.
%%                          This should be a string.
%%                 Eg: "C:\\Users\\user\\Desktop"
%% Override_globals: A boolean option if global variables should be overridden
%%                          This should be either the atoms true or false.
%%                 Eg: true
main(Filename_without_extension, Function_name, Path_to_C_file, Override_globals) :-
    util__error_if_false(string(Filename_without_extension), "Filename must be a string"),
    util__error_if_false(not string_contains(Filename_without_extension, "."), "Filename should not contain an extension"),
    util__error_if_false(atom(Function_name), "Function name must be an atom"),
    util__error_if_false(string(Path_to_C_file), "Path to C file must be a string"),
    util__error_if_false(get_file_info(Path_to_C_file, type, directory), "Path to C file is not a valid directory-path"),
    util__error_if_false(is_boolean(Override_globals), "Override globals option must be a boolean"),
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(-128, 127)),
    ptc_solver__type(boolean_int, integer, range_bounds(0, 1)),
    ptc_solver__subtype(int, integer),
    % 33-126 are the printable ASCII characters
    % https://www.ascii-code.com
    concat_string([Path_to_C_file, "/", Filename_without_extension, ".pl"], Prolog_file),
    read_prolog_file(Prolog_file, Terms),

    (Override_globals = true ->
            process_global_variables(Terms, [], All_globals),
            declare_functions(Terms),
            find_function_information(Terms, Function_name, Function_info),
            function_info__get_clean_function(Function_info, _, Parameters, Body, Return_type),
            (
                Parameters = [void] ->
                    (
                        Params = All_globals
                    )
                ;
                    (
                        append(All_globals, Parameters, Params)
                    )
            )
        ;
            process_global_variables(Terms),
            declare_functions(Terms),
            find_function_information(Terms, Function_name, Function_info),
            function_info__get_clean_function(Function_info, _, Params, Body, Return_type)
    ),

    util__error_if_false(Return_type \= void, "No unit tests to generate for a void-returning function"),
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
process_global_variables([], List_of_global_declarations, List_of_global_declarations).
process_global_variables([Term | More_terms], Global_variable_declaration_accumulator, List_of_global_declarations) :-
    % Statements 999 is a dummy variable created by the parser
    ( Term = global_variables(Statements, _), Statements \== 999 ->
        Statements = [Declaration | _],
        Declaration, % From declaration.pl
        term_variables(Declaration, [Var|_]),
        c_var__set_scope(Var, global),

        append([Declaration], Global_variable_declaration_accumulator, New_global_variable_accumulator),
        process_global_variables(More_terms, New_global_variable_accumulator, List_of_global_declarations)
    ;
        process_global_variables(More_terms, Global_variable_declaration_accumulator, List_of_global_declarations)
    ).
process_global_variables([]).
process_global_variables([Term | More_terms]) :-
    ( Term = global_variables(Statements, _), Statements \== 999 ->
        handle(Statements, return(_, _)), % From Statement_handler.pl
        process_global_variables(More_terms)
    ;
        process_global_variables(More_terms)
    ).

%% Finds the function definition for a desired function
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  Function_name: The name of the function to be found
%%  Params: The parameters of the function to be found
%%  Body: The body of the function to be found
%%  Return_type: The return type of the function to be found
find_function_information([function_definition(Function_info, _, _, _) | More_terms], Function_name, Return_function_info) :-
    !,
    function_info__get_name(Function_info, Current_function_name),
    (Current_function_name == Function_name ->
        (
            Return_function_info = Function_info,
            !
        )
    ;
        (
            find_function_information(More_terms, Function_name, Return_function_info)
        )
    ).
find_function_information([_ | More_terms], Function_name, Return_function_info) :-
    !,
    find_function_information(More_terms, Function_name, Return_function_info).
find_function_information([], Function_name, _) :-
    !,
    sprintf(Error_message, "The entry function %a cannot be found", [Function_name]),
    util__error_if_false(false, Error_message).

declare_functions([]).
declare_functions([function_definition(Function_info, Params, Body, Return_type) | More_terms]) :-
    get_var_info(Function_info, name, Function_name_as_atom),
    !,
    % Strip 'LC_' or 'UC_' from the function name
    sub_atom(Function_name_as_atom, 3, _, 0, Stripped_function_name),
    function_info__create(function_definition(Stripped_function_name, Params, Body, Return_type), Function_info),
    declare_functions(More_terms).
declare_functions([_ | More_terms]) :-
    declare_functions(More_terms).

is_boolean(true).
is_boolean(false).
