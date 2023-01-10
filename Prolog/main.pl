:- module(main).

:- export main/2.
:- export clean/0.

:- lib(ptc_solver).

:- use_module(utils).
:- use_module(c_var).
:- use_module(expressions).
:- ['statement_handler'].

%FIXME: A charpointer array can generate '\' which breaks the C code.

%% The entrypoint to the program
main(Filename_without_extension, Function_name) :-
    setup_symbolic_Execution,
    concat_string([Filename_without_extension, ".pl"], Prolog_file),
    % concat_string([File, ".c"], C_file),
    compile(Prolog_file),
    function_definition(Function_name, Params, Body, Return_type), % Match from compiled prolog file
    symbolic_Execution(Filename_without_extension, Function_name, Params, Body, Return_type). % Execute the function

%% Setup the symbolic execution environment
setup_symbolic_Execution :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(0, 255)).

function_definition(_, _, _, _). % Prevents the interpreter from warning of undefined predicates

%% The predicate to begin symbolic execution
symbolic_Execution(Filename, Function_name, Params, Body, Return_Type) :-
    setup_for_function(Filename, Function_name),
    function_handler(Filename, Function_name, Body, Params, Return_Type).

% QUESTION: How would id's work across multiple functions?
%           Possibly a merge-term of the function name per assert?
%% Setup used for each function
setup_for_function(Filename, Function_name) :-
    % FIXME: The below may not have permission to delete if the previous Prolog iteration
    % failed, mostly useful for development,
    % As the test cases will leave the streams open
    concat_string([Function_name, "_tests.c"], Test_filename),
    (
        exists(Test_filename) ->
            delete(Test_filename)
        ;
            true
    ),
    concat_string([Filename, ".names"], Names_filename),
    asserta(names_file(Names_filename)),
    asserta(test_id(1)),
    asserta(tests([])).

%% Shortcut predicate to close streams, useful for debugging.
clean :-
    ptc_solver__clean_up,
    close(testcase_read),
    close(testcase_main),
    close(testcase).
