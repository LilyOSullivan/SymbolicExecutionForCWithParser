
:- module(concretise).

:- export concretise/1.
:- export concretise/3.

:- lib(ptc_solver).
:- use_module(c_var).
:- use_module(utils).


% The cut is needed here. Otherwise Prolog attempts to match it with other concretise predicates
concretise([void]) :- !.
concretise([]).
concretise([declaration(intpointer,[H|_])|T]) :-
    get_ptc_in(H,Var),
	ptc_solver__get_array_index_elements(Var, Indexs),
	utils__get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T).

concretise([declaration(charpointer,[H|_])|T]) :-
    get_ptc_in(H,Var),
    ptc_solver__get_array_index_elements(Var, Indexs),
	utils__get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    % concretise(char(Out),Result),
    !,
    concretise(T).

concretise([declaration(int,[H|_])|T]) :-
    get_ptc_in(H,In),
    get_ptc_out(H,Out),
    ptc_solver__label_integers([In]),
    !,
    ptc_solver__label_integers([Out]),
    !,
    concretise(T).

% concretise(int(X),Out) :-
    % ptc_solver__label_integers([X]),
    % !.

concretise(char(X),Out) :-
    utils__evaluate_to_int(X,Out).
    % string_codes(Out,[Result]),


concretise(X,Type,Out) :-
    (
        Type == int ->
            utils__evaluate_to_int(X,Out)
            ;
        Type == char ->
            concretise(char(X),Out)
    ).