:- lib(ptc_solver).

:- ['statement_handler'].
% :- ['setup'].


function(_,_,Params,Body) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    param_handler(Params),
    statement_handler(Body,Params,_).


 