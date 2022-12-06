
:- module(concretise).

:- export concretise/1.
:- export concretise/3.
:- export get_all_array_inputs/2.

:- lib(ptc_solver).
:- use_module(c_var).

%FIXME: The below should be moved to a utility class
% From Eileen's Code
get_all_array_inputs([], []).
get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	get_all_array_inputs(Rest, Rest2).

% The cut is needed here. Otherwise Prolog attempts to match it with other concretise predicates
concretise([void]) :- !.
concretise([]).
concretise([declaration(intpointer,[H|_])|T]) :-
    get_ptc_var(H,Var),
	ptc_solver__get_array_index_elements(Var, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T).

concretise([declaration(charpointer,[H|_])|T]) :-
    get_ptc_var(H,Var),
    ptc_solver__get_array_index_elements(Var, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    % concretise(char(Out),Result),
    !,
    concretise(T).

concretise([declaration(int,[H|_])|T]) :-
    get_ptc_var(H,Var),
    ptc_solver__label_integers([Var]),
    !,
    concretise(T).

% concretise(int(X),Out) :-
    % ptc_solver__label_integers([X]),
    % !.

concretise(char(X),Out) :-
    evaluate_to_int(X,Out).
    % string_codes(Out,[Result]),


concretise(X,Type,Out) :-
    (
        Type == int ->
            evaluate_to_int(X,Out)
            ;
        Type == char ->
            concretise(char(X),Out)
    ).

evaluate_to_int(Expression,Out) :-
    ptc_solver__variable([Out],integer),
    ptc_solver__sdl(Out = Expression),
    !. % FIXME: Check if this leaves a choicepoint. Cut might not be needed
