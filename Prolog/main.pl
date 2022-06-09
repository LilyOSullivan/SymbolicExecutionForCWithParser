:- lib(ptc_solver).

:- ['statement_handler'].
% :- ['setup'].


function(ReturnType,FunctionName,Params,Body) :-
    ptc_solver__clean_up,
    ptc_solver__default_declarations,

    statement_handler(Params),
    statement_handler(Body),
    
    ptc_solver__label_integers(Params).


% params_to_list([],Acc,Out).
%     Out = Acc.

% params_to_listt([],Acc,Out).
%     Out = Acc.

% params_to_list([int(H)|T],Acc,Out) :-
%     append([H],Acc,Out),
%     params_to_listt(T,Acc,Out).

% params_to_listt([int(H)|T],Acc,Out) :-
%     append([H],Out,Acc),
%     params_to_list(T,Acc,Out).
