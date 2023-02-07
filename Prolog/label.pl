:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).

%% Groups variables by type and labels them collectively instead of individually
%% The parameter is a list of declaration predicates, as output by the parser
%% Eg: [declaration(integer,[x]),declaration(double,[a])]
label_collectively(Parameters) :-
    label__group_by_ptc_type(Parameters,[],Grouped_parameters),
    label(Grouped_parameters).

label([void]).
label([]).

%% Collectively pass integer-variables to be labelled to the solver
%% The parameter must be in the form [[Type,[Var1,Var2,...]]]
%% Eg: [[integer,[x,y]],[double,[a,b]]]
%% This structure is created by the predicate label__group_by_ptc_type
label([[integer,Integers_to_label]|More_to_label]) :-
    ptc_solver__label_integers(Integers_to_label),
    !,
    label(More_to_label).

label([[intpointer,Values_to_label]|More_to_label]) :-
    ( foreach(Value, Values_to_label), foreach(Array_inputs, Array_values) do
        ptc_solver__get_array_index_elements(Value, Indexs),
        utils__get_all_array_inputs(Indexs, Array_inputs)
    ),
    ptc_solver__label_integers(Array_values),
    !,
    label(More_to_label).

label([[charpointer,Values_to_label]|More_to_label]) :-
    ( foreach(Value, Values_to_label), foreach(Array_inputs, Array_values) do
        ptc_solver__get_array_index_elements(Value, Indexs),
        utils__get_all_array_inputs(Indexs, Array_inputs)
    ),
    ptc_solver__label_integers(Array_values),
    !,

    % TODO:Handle generation of backslashes and single quotes, by escaping them



    label(More_to_label).



% %% Labels an integer array
% label([declaration(intpointer, [Variable|_])|Rest]) :-
%     c_array__get_in_var(Variable, In_var),
% 	ptc_solver__get_array_index_elements(In_var, Indexs),
% 	utils__get_all_array_inputs(Indexs, Array_inputs),
%     ptc_solver__label_integers([Array_inputs]),
%     !,
%     label(Rest).

% %% Labels a character array
% label([declaration(charpointer, [H|_])|T]) :-
%     c_array__get_in_var(H, Var),
%     ptc_solver__get_array_index_elements(Var, Indexs),
% 	utils__get_all_array_inputs(Indexs, Out),
%     ptc_solver__label_integers([Out]),
%     !,
%     label(T).

% %% Labels a singular integer
% label([declaration(int, [Variable|_])|Rest]) :-
%     c_var__get_in_var(Variable, In_var),
%     ptc_solver__label_integers([In_var]),
%     !,
%     label(Rest).

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

% TODO: Make this work for arrays
% Below returns a list of the structure: [[Type,[Variables...]],[Type,[Variables...]]...]
% Eg: [[integer,[x,y]],[double,[a,b]]]
label__group_by_ptc_type([],Accumulator,Accumulator).
label__group_by_ptc_type([declaration(_type,[Variable])|More_variables],Accumulator,Grouped_by_type_result) :-
    c_var__is_variable(Variable),
    !,
    writeln("LABEL: VARIABLE"),

    c_var__get_ptc_type(Variable,Type),
    c_var__get_in_var(Variable,In_var),
    (member([Type,Vars],Accumulator) ->
        append(Vars,[In_var],New_vars),
        select([Type,Vars],Accumulator,New_accumulator),
        !,
        append(New_accumulator,[[Type,New_vars]],Accumulator2)
    ;
        append(Accumulator,[[Type,[In_var]]],Accumulator2)
    ),
    label__group_by_ptc_type(More_variables,Accumulator2,Grouped_by_type_result).

label__group_by_ptc_type([declaration(_type,[Variable])|More_variables],Accumulator,Grouped_by_type_result) :-
    c_array__is_array(Variable),
    !,
    writeln("LABEL: ARRAY"),

    c_array__get_ptc_type(Variable,Type),
    c_array__get_in_var(Variable,In_var),
    (member([Type,Vars],Accumulator) ->
        append(Vars,[In_var],New_vars),
        select([Type,Vars],Accumulator,New_accumulator),
        !,
        append(New_accumulator,[[Type,New_vars]],Accumulator2)
    ;
        append(Accumulator,[[Type,[In_var]]],Accumulator2)
    ),
    label__group_by_ptc_type(More_variables,Accumulator2,Grouped_by_type_result).


% WIP below
%% Escape backslash and single quote characters
%% First parameter is a list of ascii characters in integer form
%% Second parameter is a list of ascii characters in integer form with escaped characters
%% Eg: [104 105 39] -> [104 105 [92 39]]
label__escape_problematic_characters(Ascii,Escaped_ascii) :-
    ( foreach(Ascii_char, Ascii), foreach(Escaped_ascii_char, Escaped_ascii) do
        (
            Ascii_char == 92 ->
                Escaped_ascii_char = [92,92]
            ;
            Ascii_char == 39 ->
                Escaped_ascii_char = [92,39]
            ;
                Escaped_ascii_char = Ascii_char
        )
    ).