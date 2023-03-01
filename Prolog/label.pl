:- lib(ptc_solver).

:- use_module(c_array).
:- use_module(c_var).

%% Groups variables by type and labels them collectively instead of individually
%% The parameter is a list of declaration predicates, as output by the parser
%% Eg: [declaration(integer,[x]), declaration(double,[a])]
label_collectively([void]) :- !.
label_collectively(Parameters, Function_return_value) :-
    % Make the return value blend in as a declaration
    c_var__get_ptc_type(Function_return_value, Ptc_type),
    Function_return_as_declaration = [declaration(Ptc_type, [Function_return_value])],
    append(Parameters, Function_return_as_declaration, Parameters_and_return),

    label__group_by_ptc_type(Parameters_and_return, Grouped_parameters),
    label(Grouped_parameters).

%% Groups declarations into the following structure: [[Type,[Variable,...]],[Type,[Variable,...]]...]
%% Parameters:
%%   - List of declaration predicates, as output by the parser
%%   - Value assigned the result
%% Eg: [declaration(integer,[x]), declaration(double,[a])] -> [[integer,[x]],[double,[a]]]
label__group_by_ptc_type([], []).
label__group_by_ptc_type([declaration(_Type, [Variable]) | More_declarations], Grouped_variables) :-
    label__group_by_ptc_type(More_declarations, Grouped_declarations),
    c_var__get_ptc_type(Variable, Type),
    c_var__get_in_var(Variable, In_var),
    (
        % Check if a group of variables of the same type already exists,
        % get the group if it exists
        once select([Type, List_of_variables], Grouped_declarations, New_Grouped_declarations),
        % add to the existing group
        append(List_of_variables, [In_var], New_list_of_variables),
        % Assign back the group
        Grouped_variables = [[Type, New_list_of_variables] | New_Grouped_declarations]
    ;
        % If no group of variables of the same type exists, create a new group
        Grouped_variables = [[Type, [In_var]] | Grouped_declarations]
    ).

label([void]).
label([]).

%% Collectively pass integer-variables to be labelled to the solver
%% The parameter must be in the form [[Type,[Var1,Var2,...]]]
%% Eg: [[integer,[x,y]],[double,[a,b]]]
%% This structure is created by the predicate label__group_by_ptc_type
label([[integer,Integers_to_label] | More_to_label]) :-
    once ptc_solver__label_integers(Integers_to_label),
    label(More_to_label).

label([[intpointer,Values_to_label] | More_to_label]) :-
    ( foreach(Value, Values_to_label), foreach(Array_inputs, Array_values) do
        ptc_solver__get_array_index_elements(Value, Indexs),
        utils__get_all_array_inputs(Indexs, Array_inputs)
    ),
    once ptc_solver__label_integers(Array_values),
    label(More_to_label).

label([[charpointer,Values_to_label] | More_to_label]) :-
    ( foreach(Value, Values_to_label), foreach(Array_inputs, Array_values) do
        ptc_solver__get_array_index_elements(Value, Indexs),
        utils__get_all_array_inputs(Indexs, Array_inputs)
    ),
    once ptc_solver__label_integers(Array_values),


    % TODO:Handle generation of backslashes and single quotes, by escaping them

    label(More_to_label).

% WIP below
%% Escape backslash and single quote characters
%% First parameter is a list of ascii characters in integer form
%% Second parameter is a list of ascii characters in integer form with escaped characters
%% Eg: [104 105 39] -> [104 105 [92 39]]
label__escape_problematic_characters(Ascii, Escaped_ascii) :-
    ( foreach(Ascii_char, Ascii), foreach(Escaped_ascii_char, Escaped_ascii) do
        (
            Ascii_char == 92 -> % 92 = backslash ascii character
                Escaped_ascii_char = [92, 92]
            ;
            Ascii_char == 39 -> % 39 = single quote ascii character
                Escaped_ascii_char = [92, 39]
            ;
                Escaped_ascii_char = Ascii_char
        )
    ).