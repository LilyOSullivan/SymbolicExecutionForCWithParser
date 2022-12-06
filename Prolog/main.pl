:- lib(ptc_solver).
:- ['statement_handler'].

%FIXME: A charpointer array can generate '\' which breaks the C code.

%% The entrypoint to the program
function_definition(Function_name,Params,Body,Return_Type) :-
    setup(Function_name),
    function_handler(Function_name,Body,Params,Return_Type).

% QUESTION: How would id's work across multiple functions?
%           Possibly a merge term of the function name per assert?
setup(Function_name) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,
    ptc_solver__type(char, integer, range_bounds(0, 255)),

    concat_string([Function_name,".names"],Names_filename),
    compile(Names_filename),
    %The below May not have permission to delete if the previous Prolog iteration
    %failed, mostly useful for development,
    %As the test cases will leave the streams open
    concat_string([Function_name,"_tests.c"],Test_filename),
    (
        exists(Test_filename) ->
            delete(Test_filename)
        ;
            true
    ),
    asserta(test_id(1)),
    asserta(tests([])).

%% Shortcut predicate to close streams, useful for debugging.
clean_all :-
    ptc_solver__clean_up,
    close(testcase_read),
    close(testcase_main),
    close(testcase).
