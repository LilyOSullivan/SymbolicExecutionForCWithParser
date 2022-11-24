:- lib(ptc_solver).

:- ['statement_handler'].

%% The entrypoint to the program
function_definition(Function_Name,Params,Body,Return_Type) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    function_handler(Function_Name,Body,Params,Return_Type).
