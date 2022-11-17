:- lib(ptc_solver).

:- ['statement_handler'].

function_definition(_Function_Name,Params,Body,_Return_Type) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    function_handler(Body,Params).
