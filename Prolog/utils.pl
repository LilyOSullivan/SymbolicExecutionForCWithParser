:- lib(ptc_solver).
:- lib(regex).
% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value) | Rest], [Value | Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

%CHRIS: Ideas to make this process less-instruction-intensive
%% Removes the line number suffix from a string, output by the parser (Eg: "_183").
%% Parameters:
%%  String_with_suffix: The string to remove the suffix from
%%  String_without_suffix: The string without the suffix
%% Eg: utils__strip_suffix("__x__183", Result) -> Result = "__x_"
utils__strip_suffix(String_with_suffix, Result_without_suffix) :-
    split("(_[0-9]+)$", String_with_suffix, [], [Result_without_suffix | _]).

%% Removes the last character if it is a comma
%% Parameters:
%%  String_with_comma: The string to remove the comma from
%%  String_without_comma: The string without the comma
utils__strip_right_comma(String_with_comma, String_without_comma) :-
    (
        sub_string(String_with_comma, _, 1, 0, ",") ->
            sub_string(String_with_comma, 0, _, 1, String_without_comma)
        ;
            String_without_comma = String_with_comma
    ).

%% Join a list of strings together
%% Parameters:
%%  Strings: The list of strings to join
%%  Result: The joined string
%% Eg: join(["a","b","c"], Result) -> Result = "abc"
utils__join(Strings, Result) :-
    utils__join(Strings, "", Result).

% Join a list of strings together with a string separator
%% Parameters:
%%  Strings: The list of strings to join
%%  Separator: The string to join the strings with
%%  Result: The joined string
%% Eg: utils__join(["a","b","c"], "|", Result) -> Result = "a|b|c"
utils__join([], _, "").
utils__join([String], _, String) :- !.
utils__join([String | More_strings], Separator, Result) :-
    once utils__join(More_strings, Separator, More_strings_result),
    concat_string([String, Separator, More_strings_result], Result).

%% Assigns a value to a variable, with a return of the assigned value
%% Params:
%%  Assign_to: The variable to assign to
%%  Value: The value to assign
%%  Assigned_value: The value assigned that has been assigned
%% Eg: utils__assignment(Assign_to{"x"}, 5, Result) -> Result = 5
utils__assignment(Assign_to, Value, Assigned_value) :-
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Assigned_value], Ptc_type),
    (c_var__is_variable(Value) ->
        (
            c_var__get_out_var(Value,Value_to_assign)
        )
    ;
        (
            Value_to_assign = Value
        )
    ),
    ptc_solver__sdl(Assigned_value = Value_to_assign),
    c_var__set_out_var(Assign_to, Assigned_value).

%% Assigns arguments to parameters in a function call
%% Parameters:
%%  Arguments: The arguments to assign
%%  Parameters: The parameters to be assigned to
utils__assign_arguments_to_parameters([], []) :- !.
utils__assign_arguments_to_parameters([], [void]) :- !.
utils__assign_arguments_to_parameters([Argument | More_arguments], [declaration(Type, Parameters) | More_parameters]) :-
    declaration(Type, Parameters), % Calls declaration.pl
    Parameters = [Parameter | _],
    utils__assignment(Parameter, Argument, _),
    utils__assign_arguments_to_parameters(More_arguments, More_parameters).

%% Copies the function_information, while retaining any assigned values
%% such as global variables.
utils__get_clean_function_info(Function_info, Function_name, Parameters, Body, Return_type) :-
    function_info__get_term(Function_info, Function_definition),
    copy_term(Function_definition, Function_definition_copy, Attributed_variables_mapping),
    util__unify_copy_term_mapping(Attributed_variables_mapping),
    Function_definition_copy = function_definition(Function_name, Parameters, Body, Return_type).

%% Unifies attributed variables with the new copies creates as a result of copy_term
util__unify_copy_term_mapping([]).
util__unify_copy_term_mapping([[Attributed_variable | Free_variable] | More_variable_mappings]) :-
    Attributed_variable = Free_variable,
    util__unify_copy_term_mapping(More_variable_mappings).

%%
util__error_if_false(Goal, Error_message) :-
    (
        Goal ->
            true
        ;
            concat_string(["Error: ", Error_message], Error_message_complete),
            writeln(Error_message_complete),
            abort
    ).

%% Convert a c-type to a ptc-type
utils__c_to_ptc_type(int, integer).
