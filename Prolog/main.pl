:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(function_info).

:- ['variable_sizes'].
:- ['memory_model'].
:- ['declaration'].
:- ['expressions'].
:- ['statement_handler'].
:- ['utils'].

%% sub_atom/5 is used in creating function_info variables.
%% It strips the LC_/UC_ from the function name, while retaining it as an atom.
:- import sub_atom/5 from iso_light.

%$ Used in regression_main/1 to convert an atom to a string
:- import atom_codes/2 from iso_light.

%% Prolog Global values (getval/2, setval/2):
%%  test_folder_path (String): The path to the folder where the test-cases are generated
%%  test_id (Number, value:1): This is an Id used to identify test cases generated
%%  tests (List, value:[]): This list holds the names of the generated test cases
%%      Eg: ["test_1", "test_2", "test_3"...]
%%  free_address (Number, value: 1000): This is the address of the next free memory location in the memory model

%% Prolog Global References (getref/2, setref/2):
%%  memory_model (hash, key: integer(getval(free_address)), value: c_var): Global memory model (In the form of a hash table)

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
    validate_inputs(Filename_without_extension, Function_name, Path_to_C_file, Override_globals),
    setup_test_driver(Function_name, Path_to_C_file),
    setup_ptc_solver,
    concat_string([Path_to_C_file, "/", Filename_without_extension, ".pl"], Prolog_filepath),
    get_function_information_from_parsed_file(Prolog_filepath, Override_globals, Function_name, Params, Body, Return_type),
    symbolically_execute_function(Filename_without_extension, Function_name, Body, Params, Return_type). % From Statement_handler.pl

%% validate_inputs/4
%% validate_inputs(+Filename_without_extension, +Function_name, +Path_to_C_file, +Override_globals)
%% Validates the inputs to main/4
%% Parameters:
%%  Filename_without_extension: The name of the file without the .pl extension
%%  Function_name: The entry function to be tested. This should be an atom.
%%  Path_to_C_file: The folder-path to the C file to be symbolically executed.
%%  Override_globals: A boolean option if global variables should be overridden at test-generation time
validate_inputs(Filename_without_extension, Function_name, Path_to_C_file, Override_globals) :-
    utils__error_if_false(string(Filename_without_extension), "Filename must be a string"),
    utils__error_if_false(not string_contains(Filename_without_extension, ".pl"), "Filename should not contain an extension"),
    utils__error_if_false(atom(Function_name), "Function name must be an atom"),
    utils__error_if_false(string(Path_to_C_file), "Path to C file must be a string"),
    utils__error_if_false(get_file_info(Path_to_C_file, type, directory), "Path to C file is not a valid directory-path"),
    utils__error_if_false(once member(Override_globals, [false, true]), "Override globals option must be an atom of a boolean ('true' or 'false')").

%% setup_test_driver/2
%% setup_test_driver(+Function_name, +Path_to_C_file)
%% Setup for the test-driver
%% Parameters:
%%  Function_name: The entry function to be tested. This should be an atom.
%%                 Eg: get_sign
%%  Path_to_C_file: The folder-path to the C file to be symbolically executed. This is a string
setup_test_driver(Function_name, Path_to_C_file) :-
    % Format: 24Hours_Minutes_Seconds__days_months_year
    % Eg: 14_34_18__03_02_23
    get_flag(unix_time, Unix_time),
    local_time_string(Unix_time,"%H_%M_%S__%d_%m_%y", Date_string),
    concat_string([Path_to_C_file, "/", Function_name, "_tests_", Date_string, "/"], Path_to_test_directory),

    % Foldername used for the generated test-cases
    setval(test_folder_path, Path_to_test_directory),

    % The initial Id used to identify test cases generated. Used in test_generation.pl
    setval(test_id, 1),

    % A list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl
    % when generating the '_main' cunit .c file
    setval(tests, []),

    % A value holding the next free address in the memory model. Used in memory_model.pl
    setval(free_address, 1000),
    initialise_memory_model.

setup_ptc_solver :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(boolean_int, integer, range_bounds(0, 1)),
    % ptc_solver__subtype(int, integer),
    declare_c_types_to_ptc_solver.
    % ptc_solver__type(char, integer, range_bounds(-128, 127)),
    % ptc_solver__type(pointer, integer, range_bounds(0, 200000)).

declare_c_types_to_ptc_solver :-
    get_type_information(Type, _, Minimum_bound, Maximum_bound),
    (integer(Maximum_bound) ->
        ptc_solver__type(Type, integer, range_bounds(Minimum_bound, Maximum_bound))
    ;
        true
        % Type \= float
        % ptc_solver__type(Type, float, range_bounds(Minimum_bound, Maximum_bound))
    ),
    fail.
declare_c_types_to_ptc_solver.

%% get_function_information_from_parsed_file/6
%% get_function_information_from_parsed_file(+Parsed_file_path, +Override_globals, +Function_name, -Processed_parameters, -Body, -Return_type)
%% Reads the parser-result prolog file, and returns the function_info of the entry function
%% Parameters:
%%  Parsed_file_path: The path to the prolog file to be read. This is a string
%%  Override_globals: A boolean option if global variables should be overridden at test-generation time
%%  Function_name: The name of the function to be found. This is an atom
%%  Processed_parameters: The list of parameters to the entry function
%%  Body: The body of the entry function
%%  Return_type: The return type of the entry function
get_function_information_from_parsed_file(Parsed_file_path, Override_globals, Function_name, Processed_parameters, Body, Return_type) :-
    read_prolog_file(Parsed_file_path, Terms),
    process_global_variables(Terms, All_globals),

    declare_functions(Terms, Function_name, Function_info),
    sprintf(Error_message, "The entry function '%a' cannot be found", [Function_name]),
    utils__error_if_false(not free(Function_info), Error_message),

    function_info__get_clean_function(Function_info, _, Parameters, Body, Return_type),
    utils__error_if_false(Return_type \= void, "No unit tests to generate for a void-returning function"),
    declare_static_variables(Body),
    override_globals(Override_globals, All_globals, Parameters, Processed_parameters).

%% read_prolog_file/2
%% read_prolog_file(+Relative_path, -Read_prolog_terms)
%% Reads the parser-result prolog file, and returns its' contents
%% This is used in place of the compile predicate. The compile predicate
%% strips variable names when compiling.
%% Parameters:
%%  Relative_path: The path to the prolog file to be read
%%  Read_prolog_terms: The contents of the prolog file
read_prolog_file(Relative_path, Read_prolog_terms) :-
    open(Relative_path, read, Stream),
    % Asserting breaks the variable links.
    % Return the content directly instead.
    read_term(Stream, Parsed_terms, []),
    close(Stream),
    Parsed_terms = parsed(Read_prolog_terms).

%% process_global_variables/2
%% process_global_variables(+Terms, -List_of_global_declarations)
%% Initialise global variables
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  List_of_global_declarations: The list of global declarations
process_global_variables(Terms, List_of_global_declarations) :-
    process_global_variables(Terms, [], List_of_global_declarations).

process_global_variables([], List_of_global_declarations, List_of_global_declarations) :- !.
process_global_variables([global_variables([Declaration | _], _) | More_terms], Global_declaration_accumulator, List_of_global_declarations) :-
    Declaration, % From declaration.pl
    term_variables(Declaration, [Global_variable | _]),
    c_var__set_scope(Global_variable, global),
    process_global_variables(More_terms, [Declaration | Global_declaration_accumulator], List_of_global_declarations).
process_global_variables([_ | More_terms], Global_declaration_accumulator, List_of_global_declarations) :-
    process_global_variables(More_terms, Global_declaration_accumulator, List_of_global_declarations).

%% declare_static_variables/1
%% declare_static_variables(+Body)
%% Declares functions as attributed variables and returns a desired function_info
%% Parameters:
%%  Terms: The contents of the parser-result prolog file
%%  Function_name: The name of the function to be found
%%  Function_info: The function_info matching to the function_name
declare_functions([], _, _).
declare_functions([function_definition(Function_info, Params, Body, Return_type) | More_terms], Function_name_to_be_found, Found_function) :-
    get_var_info(Function_info, name, Function_name_as_atom),
    !,
    % Strip 'LC_' or 'UC_' from the function name
    sub_atom(Function_name_as_atom, 3, _, 0, Stripped_function_name),
    function_info__create(function_definition(Stripped_function_name, Params, Body, Return_type), Function_info),
    (Stripped_function_name = Function_name_to_be_found ->
        Found_function = Function_info
    ;
        true
    ),
    declare_functions(More_terms, Function_name_to_be_found, Found_function).
declare_functions([_ | More_terms], Function_name_to_be_found, Function_info) :-
    declare_functions(More_terms, Function_name_to_be_found, Function_info).

override_globals(true, All_globals, [void], All_globals) :- !.
override_globals(true, All_globals, Function_parameters, Parameters) :-
    append(All_globals, Function_parameters, Parameters).
override_globals(false, _, Parameters, Parameters).
