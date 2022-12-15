:- module(main).

:- export main/2.
:- export clean/0.
:- export temp/0.

:- lib(ptc_solver).
:- use_module(utils).
:- use_module(c_var).
:- use_module(expressions).
:- ['statement_handler'].

%FIXME: A charpointer array can generate '\' which breaks the C code.

%% The entrypoint to the program
main(File,Function_name) :-
    concat_string([File,".pl"],Prolog_file),
    % concat_string([File,".c"],C_file),
    compile(Prolog_file),
    function_definition(Function_name,Params,Body,Return_type), % Match from database
    symbEx(File,Function_name,Params,Body,Return_type). % Execute the function

symbEx(Filename,Function_name,Params,Body,Return_Type) :-
    setup(Filename,Function_name),
    function_handler(Filename,Function_name,Body,Params,Return_Type).

% QUESTION: How would id's work across multiple functions?
%           Possibly a merge-term of the function name per assert?
setup(Filename,Function_name) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(0, 255)),
    %FIXME: The below May not have permission to delete if the previous Prolog iteration
    %failed, mostly useful for development,
    %As the test cases will leave the streams open
    concat_string([Function_name,"_tests.c"],Test_filename),
    (
        exists(Test_filename) ->
            delete(Test_filename)
        ;
            true
    ),
    concat_string([Filename,".names"],Names_filename),
    asserta(names_file(Names_filename)),
    asserta(test_id(1)),
    asserta(tests([])).

%% Shortcut predicate to close streams, useful for debugging.
clean :-
    ptc_solver__clean_up,
    close(testcase_read),
    close(testcase_main),
    close(testcase).


temp :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__variable([Out],integer),
    ptc_solver__variable([In],integer),
    ptc_solver__sdl(Out = In + 1),
    ptc_solver__label_integers([Out,In]),!.