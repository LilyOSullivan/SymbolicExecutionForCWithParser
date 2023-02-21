:- lib(ptc_solver).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

utils__detect_not_all_code_paths_return(Return_value, Return_type) :-
    (Return_type \== void, free(Return_value) ->
        (
            writeln("SOURCE-ERROR: Not all code paths return a value!!"),
            Return_value = 0
        )
    ;
        (
            true % All okay, no error
        )
    ).

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

% Join a list of strings together
% Eg: join(["a","b","c"],Result) -> Result = "abc"
utils__join([], "").
utils__join([String|More_strings], Result) :-
    utils__join(More_strings, Strings_join_so_far),
    concat_string([String, Strings_join_so_far], Result).

%% Assigns a value to a variable, with a return of the assigned value
%% Params:
%%  Assign_to: The variable to assign to
%%  Value: The value to assign
%%  Assigned_value: The value assigned that has been assigned
%% Eg: utils__assignment(Assign_to{"x"}, 5, Result) -> Result = 5
utils__assignment(Assign_to, Value, Assigned_value) :-
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Assigned_value], Ptc_type),
    ptc_solver__sdl(Assigned_value = Value),
    c_var__set_out_var(Assign_to, Assigned_value).

%% Assigns arguments to parameters in a function call
%% Parameters:
%%  Arguments: The arguments to assign
%%  Parameters: The parameters to be assigned to
utils__assign_arguments_to_parameters([], []).
utils__assign_arguments_to_parameters([Argument | More_arguments], [declaration(Type,Parameters) | More_parameters]) :-
    declaration(Type, Parameters), % Calls declaration.pl
    Parameters = [Parameter | _],
    utils__assignment(Parameter, Argument, _),
    utils__assign_arguments_to_parameters(More_arguments, More_parameters).

%% Normalises the return value of a function.
%% Params
%%  Return_value: The value returned by the function
%%  Return_type: The return type of the function
%%  Normalised_return_value: The 'Return_value' normalised
%% Eg: utils__normalise_return(1+5-0, int, Result) -> Result = 6
utils__normalise_return(Return_value,Return_type,Normalised_return_value) :-
    (Return_type \== void ->
        (
            utils__c_to_ptc_type(Return_type, Ptc_type),
            ptc_solver__variable([Normalised_return_value], Ptc_type),
            ptc_solver__sdl(Normalised_return_value = Return_value),
            ptc_solver__label_integers([Normalised_return_value]),
            !
        )
    ;
        (
            Normalised_return_value = Return_value
        )
    ).

%% Convert a c-type to a ptc-type
utils__c_to_ptc_type(int,integer).