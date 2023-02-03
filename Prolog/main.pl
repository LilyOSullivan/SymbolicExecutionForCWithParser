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

%% The entrypoint to the program
%% Filename_without_extension: The name of the file without the .pl extension
%%                             This should be a string. Eg: "sign"
%% Function_name: The entry function to be tested. This should be an atom.
%                 Eg: get_sign
main(Filename_without_extension, Function_name) :-
    string(Filename_without_extension),
    atom(Function_name),

    setup_symbolic_Execution,
    concat_string([Filename_without_extension, ".pl"], Prolog_file),
    compile(Prolog_file),
    % concat_string([File, ".c"], C_file),
    function_definition(Function_name, Params, Body, Return_type), % Match from compiled prolog file
    setup_for_function(Filename_without_extension, Function_name),
    function_handler(Filename_without_extension, Function_name, Body, Params, Return_type). % From Statement_handler.pl

%% Setup the symbolic execution environment
setup_symbolic_Execution :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(33, 126)).
    % 33-126 are the printable ASCII characters
    % https://www.ascii-code.com

% IDEA: Name predicate: setup_test_driver
% QUESTION: How would id's work across multiple functions?
%           Possibly a merge-term of the function name per setval?
%% Setup used for each function by the test-driver
setup_for_function(Filename, Function_name) :-
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
    % utils__strip_right_newline(Current_date_as_string, Current_date_stripped_with_spaces),
    % utils__replace_invalid_directory_chars_with_underscores(Current_date_stripped_with_spaces, Current_date_cleaned),
    concat_string([Function_name, "_tests_",Current_date_as_string], Folder_name),
    concat_string(["./", Folder_name, "/"], Path_to_test_directory),
    setval(test_folder_path,Path_to_test_directory),

    % The initial Id used to identify test cases generated. Used in test_generation.pl
    setval(test_id,1),

    % A list holding the names of test cases in the form ["test_1","test_2"...] used in test_generation.pl
    % when generating the '_main' cunit .c file
    setval(tests,[]).

%% Shortcut predicate to close streams, useful for debugging.
clean :-
    ptc_solver__clean_up,
    close(testcase_read),
    close(testcase_main),
    close(testcase).
