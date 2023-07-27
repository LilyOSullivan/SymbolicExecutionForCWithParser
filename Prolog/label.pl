:- lib(ptc_solver).

% :- use_module(c_array).
:- use_module(c_var).

%% Groups variables by type and labels them collectively instead of individually
%% The parameter is a list of declaration predicates, as output by the parser
%% Eg: [declaration(int,[x], []), declaration(double, [a], [])]
label_collectively([void]) :- !.
label_collectively(Parameters) :-
    label__group_by_type(Parameters, Grouped_parameters),
    label(Grouped_parameters),
    !.

%% Groups declarations into the following structure: [[Type,[Variable,...]],[Type,[Variable,...]]...]
%% Parameters:
%%   - List of declaration predicates, as output by the parser
%%   - Value assigned the result
%% Eg: [declaration(int, [x], []), declaration(double, [a], [])] -> [[int,[x]],[double,[a]]]
label__group_by_type([], []) :- !.
label__group_by_type([declaration(Type, [Variable], _) | More_declarations], Grouped_variables) :-
    label__group_by_type(More_declarations, Grouped_declarations),
    c_var__get_in_var(Variable, In_var),
    (
        % Check if a group of variables of the same type already exists,
        % get the group if it exists
        once select(label_variables(Type, List_of_variables), Grouped_declarations, New_Grouped_declarations),
        % Add to the existing group
        append(List_of_variables, [In_var], New_list_of_variables),
        % Assign back the group
        Grouped_variables = [label_variables(Type, New_list_of_variables) | New_Grouped_declarations]
    ;
        % If no group of variables of the same type exists, create a new group
        Grouped_variables = [label_variables(Type, [In_var]) | Grouped_declarations]
    ).

label([]) :- !.

%% Collectively pass integer-variables to be labelled to the solver
%% The parameter must be in the form [[Type,[Var1,Var2,...]]]
%% Eg: [[int,[x,y]],[double,[a,b]]]
%% This structure is created by the predicate label__group_by_type
label([label_variables(_Type, Variables_to_label) | More_to_label]) :-
    Variables_to_label = [First_value_to_label | _],
    (ptc_solver__is_integer(First_value_to_label) ->
        ptc_solver__label_integers(Variables_to_label)
    ;
        ptc_solver__label_reals(Variables_to_label)
    ),
    label(More_to_label).

% label([label_variables(intpointer, Values_to_label) | More_to_label]) :-
%     ( foreach(Value, Values_to_label), foreach(Array_inputs, Array_values) do
%         ptc_solver__get_array_index_elements(Value, Indexs),
%         utils__get_all_array_inputs(Indexs, Array_inputs)
%     ),
%     ptc_solver__label_integers(Array_values),
%     label(More_to_label).

