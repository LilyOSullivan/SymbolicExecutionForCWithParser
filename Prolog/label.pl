:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).

% The cut is needed here. Otherwise Prolog attempts to match it with other label predicates
label([void]) :- !.
label([]).

%% Labels an integer array
label([declaration(intpointer, [Variable|_])|Rest]) :-
    c_array__get_in_var(Variable, In_var),
	ptc_solver__get_array_index_elements(In_var, Indexs),
	utils__get_all_array_inputs(Indexs, Array_inputs),
    ptc_solver__label_integers([Array_inputs]),
    !,
    label(Rest).

%% Labels a character array
label([declaration(charpointer, [H|_])|T]) :-
    c_array__get_in_var(H, Var),
    ptc_solver__get_array_index_elements(Var, Indexs),
	utils__get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    label(T).

%% Labels a singular integer
label([declaration(int, [Variable|_])|Rest]) :-
    c_var__get_in_var(Variable, In_var),
    ptc_solver__label_integers([In_var]),
    !,
    label(Rest).

% IDEA: This predicate is a likely candidate to be removed
%% Label an expression passed in based on the type desired
%% This label variant is called upon a return statement
label(Expression, Type, Concrete_variable) :-
    (
        Type == int ->
            utils__evaluate_to_int(Expression, Concrete_variable)
            ;
        Type == char ->
            utils__evaluate_to_int(Expression, Concrete_variable)
    ).
