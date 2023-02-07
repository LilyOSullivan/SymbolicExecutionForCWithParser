:- lib(ptc_solver).

:- ['utils'].
:- use_module(c_var).
:- use_module(expressions).
:- ['statement_handler'].

:- dynamic var_names/2.

%% Global values:
%%  test_id (Number, value:1): This is an Id used to identify test cases generated
%%  tests (List, value:[]): This list holds the names of the generated test cases
%%      Eg: ["test_1","test_2","test_3"...]

%FIXME: A charpointer array can generate '\' which breaks the C code.
% ASCII code: 92

%% Run regression tests
%% Filename_without_extension: The name of the parsed prolog file without the .pl extension
%%                             This should be a string.
%%                 Eg: "regression"
regression_tests(Filename_without_extension) :-
    string(Filename_without_extension),
    concat_string([Filename_without_extension, ".pl"], Prolog_file),
    compile(Prolog_file),
    function_definition(Function_name, Parameters, Body, Return_type),
    main(Filename_without_extension, Function_name, "Z:/Documents/Github/SymbolicExecutionForCWithParser/LexYacc"),
    % Compile test cases
    getval(test_folder_path,Path_to_test_directory),
    concat_string([Function_name,"_tests_main.c"], Main_filename),
    concat_string([Path_to_test_directory,Main_filename], Path_to_main),

    % Compile the main test file
    sprintf(Compile_string,"cd %s && x86_64-w64-mingw32-gcc -o %s.exe %s -lcunit", [Path_to_test_directory, Function_name, Path_to_main]),
    (sh(Compile_string) ->
        true
    ;
        printf("Failed to compile test cases: %s",[Function_name]),
        halt(2) % Halt 2 is considered a more major error than 1
    ),

    % Run test cases
    sprintf(Run_string,"cd %s && %s.exe", [Path_to_test_directory, Function_name]),
    (sh(Run_string) ->
        true
    ;
        printf("Test cases encountered failure: %s",[Function_name]),
        halt(1) % Halt 1 is considered a more minor error than 2
    ),
    fail.
regression_tests(_).


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

    concat_string([Filename_without_extension, ".pl"], Prolog_file),
    compile(Prolog_file),
    function_definition(Function_name, Params, Body, Return_type), % Match from compiled prolog file
    !,
    setup_for_function(Filename_without_extension, Function_name,Path_to_C_file),
    function_handler(Filename_without_extension, Function_name, Body, Params, Return_type). % From Statement_handler.pl

% IDEA: Name predicate: setup_test_driver
% QUESTION: How would id's work across multiple functions?
%           Possibly a merge-term of the function name per setval?
%% Setup used for each function by the test-driver
setup_for_function(Filename, Function_name,Path_to_C_file) :-
    % FIXME: The below may not have permission to delete if the previous Prolog iteration
    % failed, mostly useful for development,
    % As the test cases will leave the streams open
    concat_string([Filename, ".names"], Names_filename),
    compile(Names_filename),

    % Foldername used for the generated test cases
    get_flag(unix_time,Unix_time),

    % Format: days/months/year__24Hours_Minutes_Seconds
    % Eg: 03_02_23__14_34_18
    local_time_string(Unix_time,"%d_%m_%y__%H_%M_%S",Current_date_as_string),
    concat_string([Function_name, "_tests_",Current_date_as_string], Folder_name),
    concat_string([Path_to_C_file,"/", Folder_name, "/"], Path_to_test_directory),
    setval(test_folder_path,Path_to_test_directory),

    % The initial Id used to identify test cases generated. Used in test_generation.pl
    setval(test_id,1),

    % A list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl
    % when generating the '_main' cunit .c file
    setval(tests,[]).

%% Shortcut predicate to close streams, useful for debugging.
%% This predicate is only used during development; It is not called in code
clean :-
    ptc_solver__clean_up,
    close(testcase_read),
    close(testcase_main),
    close(testcase).
