:- lib(ptc_solver).

:- ['statement_handler'].


function(_,_,Params,Body) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    function_handler(Body,Params).
