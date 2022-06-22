function_handler(Body,Params) :-
    parameter_handler(Params),
    statement_handler(Body,_),
    label(Params).

label(Params) :-
    ptc_solver__label_integers(Params),
    !.

parameter_handler([]).
parameter_handler([H|T]) :-
    handle(H),
    parameter_handler(T).

statement_handler([],_).
statement_handler([H|T],Return_flag) :-
    handle(H,Return_flag),
    (
        Return_flag == true ->
            true
        ;
            statement_handler(T,Return_flag)
    ).

handle(int(X)) :-
    ptc_solver__variable([X],integer).

handle(if_stmt(Constraint,If_body),Return_flag) :-
    handle(if_stmt(Constraint,If_body,[]),Return_flag).

handle(if_stmt(Constraint,If_body,Else_body),Return_flag) :-
    (
        ptc_solver__sdl(Constraint),
        statement_handler(If_body,Return_flag)
    )
        ; % Deliberate Choice Point
    (
        ptc_solver__sdl(not Constraint),
        statement_handler(Else_body,Return_flag)
    ).

handle(return(Expression),Return_flag) :-
    Return_flag = true,
    writeln(Expression).

% Create an assignment handler
handle(assignment(X,Expression),_) :-
    % handle(X),
    ptc_solver__sdl(eq_cast(X, Expression)).