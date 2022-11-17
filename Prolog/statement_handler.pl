:- ['utilities'].
:- ['expression'].

function_handler(Body,Params) :-
    parameter_handler(Params),
    statement_handler(Body,_),
    concretise(Params). % QUESTION Label on return statement

% From Eileens Code
get_all_array_inputs([], []).
get_all_array_inputs( [(_, Value)|Rest], [Value|Rest2]) :-
	get_all_array_inputs(Rest, Rest2).

concretise([]).
concretise([declaration(intpointer,[H|T])|TT]) :-
	ptc_solver__get_array_index_elements(H, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T), % This labels single-line declarations: int a,b;
    concretise(TT).

concretise([declaration(int,[H|T])|TT]) :-
    ptc_solver__label_integers([H]),
    !,
    concretise(T),
    concretise(TT).

parameter_handler([]).
parameter_handler([H|T]) :-
    H,
    parameter_handler(T).

declaration(_,[]).
declaration(int,[H|T]) :-
    ptc_solver__variable([H],integer),
    declaration(int,T),
    !.

declaration(intpointer,[H|T]) :-
    % term_string(IndexType,"indexType5"),
    % term_string(ArrayType,"arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([H], arrayType5),
    ptc_solver__is_array(H),
    declaration(intpointer,T),
    !.

statement_handler([],_).
statement_handler([H|T],Return_flag) :-
    handle(H,Return_flag),
    (
        Return_flag == true ->
            true
        ;
            statement_handler(T,Return_flag)
    ).

% handle(int(X)) :-
%     ptc_solver__variable([X],integer).


handle(if_statement(_Line_Number,expression(Constraint),If_body,Else_body),Return_flag) :-
    evaluate_expression(Constraint),
    (
        statement_handler(If_body,Return_flag)
    )
        ; % Deliberate Choice Point
    (
        evaluate_expression(not(Constraint)),
        statement_handler(Else_body,Return_flag)
    ).

handle(return(Expression),Return_flag) :-
    Return_flag = true,
    evaluate_expression(Expression,Out),
    writeln(Out).


handle(assignment(int(Z),extern(f(X),Library_Name)),_) :-
    ptc_solver__variable([X],integer),
    ptc_solver__variable([Z],integer),
    handle(extern(f(X),Library_Name),Z),
    !.

% handle(assignment(int(X),Value),_) :-
%     handle(int(X)),
%     ptc_solver__sdl(eq_cast(X, Value)).

handle(extern(f(X),Library_Name),Out) :-
    (
        var(X) ->
            suspend(
                handle(extern(f(X),Library_Name),Out),
                1,
                X->inst
            )
        ;
            load(Library_Name),
            external(external_call/2,p_external_call),
            external_call(Result,X),
            writeln(Result),
            ptc_solver__sdl(eq_cast(Out, Result))
    ).

