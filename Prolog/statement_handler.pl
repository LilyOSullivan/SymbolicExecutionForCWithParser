
statement_handler([]).

statement_handler([H|T]) :-
    handle(H),
    statement_handler(T).

handle(int(X)) :-
    ptc_solver__variable([X],integer).

handle(ifStmt(Constraint,If_body)) :-
    handle(ifStmt(Constraint,If_body,[])).

% handle(ifStmt(Constraint,If_body)) :-
%     (
%         ptc_solver__sdl(Constraint)
%             ->
%                 statement_handler(If_body)
%     ).

handle(ifStmt(Constraint,If_body,Else_body)) :-
    (
        ptc_solver__sdl(Constraint)
            ->
                statement_handler(If_body)
            ;
                statement_handler(Else_body)

    ).

handle(return(Expression)) :-
    writeln(Expression).




