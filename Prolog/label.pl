:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).

% The cut is needed here. Otherwise Prolog attempts to match it with other label predicates
label([void]).
label([]).

%% Collectively pass variables to be labelled to the solver
label([[integer,Integers_to_label]|More_to_label]) :-
    ptc_solver__label_integers(Integers_to_label),
    !,
    label(More_to_label).

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

%% Groups variables by type and labels them collectively instead of individually
label_collectively(Parameters) :-
    label__group_by_ptc_type(Parameters,[],Grouped_parameters),
    label(Grouped_parameters),!

% TODO: Make this work for arrays
% Below returns a list of the structure: [[Type,[Variables...]],[Type,[Variables...]]...]
% Eg: [[integer,[x,y]],[double,[a,b]]]
label__group_by_ptc_type([],Accumulator,Accumulator).
label__group_by_ptc_type([declaration(_type,[Variable])|More_variables],Accumulator,Out) :-
        is_list(Accumulator),
        c_var__is_variable(Variable),

        c_var__get_ptc_type(Variable,Type),
        c_var__get_in_var(Variable,In_var),
        (
            member([Type,Vars],Accumulator) ->
                append(Vars,[In_var],New_vars),
                select([Type,Vars],Accumulator,New_accumulator),
                append(New_accumulator,[[Type,New_vars]],Accumulator2)
            ;
                append(Accumulator,[[Type,[In_var]]],Accumulator2)
        ),
        label__group_by_ptc_type(More_variables,Accumulator2,Out).