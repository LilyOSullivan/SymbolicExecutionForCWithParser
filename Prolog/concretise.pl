:- module(concretise).

:- export concretise/1.
:- export concretise/3.

:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).
:- use_module(utils).

% The cut is needed here. Otherwise Prolog attempts to match it with other concretise predicates
concretise([void]) :- !.
concretise([]).

%% Labels an integer array
concretise([declaration(intpointer, [Variable|_])|Rest]) :-
    c_array__get_in_var(Variable, In_var),
	ptc_solver__get_array_index_elements(In_var, Indexs),
	utils__get_all_array_inputs(Indexs, Array_inputs),
    ptc_solver__label_integers([Array_inputs]),
    !,
    concretise(Rest).

%% Labels a character array
concretise([declaration(charpointer, [H|_])|T]) :-
    c_array__get_in_var(H, Var),
    ptc_solver__get_array_index_elements(Var, Indexs),
	utils__get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T).

%% Labels a singular integer
concretise([declaration(int, [Variable|_])|Rest]) :-
    c_var__get_in_var(Variable, In_var),
    ptc_solver__label_integers([In_var]),
    !,
    concretise(Rest).

% IDEA: This predicate is a likely candidate to be removed
%% Label an expression passed in based on the type desired
%% This concretise variant is called upon a return statement
concretise(Expression, Type, Var_concrete) :-
    (
        Type == int ->
            utils__evaluate_to_int(Expression, Var_concrete)
            ;
        Type == char ->
            utils__evaluate_to_int(Expression, Var_concrete)
    ).
