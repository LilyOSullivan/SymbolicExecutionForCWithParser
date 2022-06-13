function_handler(Body,Params) :-
    param_handler(Params),
    statement_handler(Body,Params,_),


param_handler([]).
param_handler([H|T]) :-
    handle(H),
    param_handler(T).

statement_handler([],_,_).
statement_handler([H|T],Params,ReturnFlag) :-
    handle(H,Params,ReturnFlag),
    (
        ReturnFlag == true
    )
        ;
    (
        statement_handler(T,Params,ReturnFlag)
    ).

handle(int(X)) :-
    ptc_solver__variable([X],integer).

handle(ifStmt(Constraint,If_body),Params,ReturnFlag) :-
    ptc_solver__sdl(Constraint),
    statement_handler(If_body,Params,ReturnFlag).

handle(ifStmt(Constraint,If_body,Else_body),Params,ReturnFlag) :-
    (
        ptc_solver__sdl(Constraint),
        statement_handler(If_body,Params,ReturnFlag)
    )
        ;
    (
        ptc_solver__sdl(not Constraint),
        statement_handler(Else_body,Params,ReturnFlag)
    ).

handle(return(Expression),Params,ReturnFlag) :-
    ReturnFlag = true,
    ptc_solver__label_integers(Params),
    writeln(Expression),
    !.  % solves:
        %function(int,get_sign,[int(X)],[ifStmt(X<0,[return(-1)])]).

