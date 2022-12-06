:- lib(ptc_solver).

:- ['statement_handler'].


%% The entrypoint to the program
function_definition(Function_name,Params,Body,Return_Type) :-
    setup(Function_name),
    function_handler(Function_name,Body,Params,Return_Type).

% QUESTION: How would this work across multiple functions?
%           Possibly a merge term of the function name per assert?
setup(Function_name) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    concat_string([Function_name,".names"],Names_filename),
    compile(Names_filename),
    %FIXME: May not have permission to delete if the previous Prolog iteration
    %       failed, as it will remain having the file stream unclosed.
    concat_string([Function_name,"_tests.c"],Test_filename),
    (
        exists(Test_filename) ->
            delete(Test_filename)
        ;
            true
    ),
    asserta(test_id(1)),
    asserta(tests([])).

%This is used for debugging purposes
clean_all :-
    ptc_solver__clean_up,
    retractall(test_id(_)),
    retractall(tests(_)),
    close(testcase_read),
    close(testcase_main),
    close(testcase).
