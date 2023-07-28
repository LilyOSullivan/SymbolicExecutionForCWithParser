:- lib(ptc_solver).
:- lib(regex).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value) | Rest], [Value | Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).


is_static_declaration(declaration(Functor, [Variable], _)) :-
    atom(Functor),
    var(Variable),
    sub_atom(Functor, 0, _, _, 'static_').

is_static_declared(declaration(Functor, [Variable], _)) :-
    is_static_declaration(declaration(Functor, [Variable], _)),
    c_var__is_variable(Variable).

is_static_undeclared(declaration(Functor, [Variable], _)) :-
    is_static_declaration(declaration(Functor, [Variable], _)),
    not c_var__is_variable(Variable).

declare_static_variables([]).
declare_static_variables([Statement | More_statements]) :-
    ( is_static_undeclared(Statement) ->
        declaration(Type, [Variable], Assignment) = Statement,
        % Strip "static_" from the start of the 'Type' string
        sub_atom(Type, 7, _, 0, Type_without_static),
        declaration(Type_without_static, [Variable], Assignment),
        ( Assignment = [] ->
                %% 6.7.9 Initialization - clause 10
                %% "If an object that has static.. storage duration... is not initialized explicitly...
                %%  if it has arithmetic type, it is initialized to (positive or unsigned) zero"
                utils__assignment(Variable, 0, _)
            ;
                true
        )
    ;
        true
    ),
    declare_static_variables(More_statements).

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

%% Join a list of strings together with a string separator
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
%% Parameters:
%%  Assign_to: The variable to assign to
%%  Value: The value to assign
%%  Assigned_value: The value assigned that has been assigned
%% Eg: utils__assignment(Assign_to{"x"}, 5, Result) -> Result = 5
utils__assignment(Assign_to, Value, Assigned_value) :-
    c_var__is_variable(Assign_to),
    c_var__get_type(Assign_to, Type),
    ptc_solver__variable([Assigned_value], Type),
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
utils__assign_arguments_to_parameters([Argument | More_arguments], [declaration(Type, Parameters, Assignment) | More_parameters]) :-
    declaration(Type, Parameters, Assignment), % Calls declaration.pl
    Parameters = [Parameter | _],
    utils__assignment(Parameter, Argument, _),
    utils__assign_arguments_to_parameters(More_arguments, More_parameters).

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

%% Truncate a whole number by its binary digits to fit an integer range.
%% Parameters:
%%  Number_to_truncate: the value to be truncated
%%  Min_bound: the minimum value in the range
%%  Max_bound: the maximum value in the range
%%  Result: the final truncated number

%% 6.3.1.3 Signed and unsigned integers - Clause 2
%%      "the value is converted by repeatedly adding or subtracting one more
%%      than the maximum value that can be represented in the new type until the value
%%      is in the range of the new type."
%% https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
utils__truncate(Number_to_truncate, Min_bound, Max_bound, Result) :-
    integer(Min_bound),
    integer(Max_bound),
    integer(Number_to_truncate),

    Min_bound =< Max_bound,

    %% Calculate the range size, and adjust the range size for bit_length calculation
    Range_size is Max_bound - Min_bound + 1,
    Adjusted_range_size is Range_size - 1,

    bit_length(Adjusted_range_size, Bit_length),

    %% Create a mask to truncate the number to the necessary number of bits
    Mask is (1 << Bit_length) - 1,

    %% Calculate the midpoint value of the range, to distinguish between positive and negative numbers
    Mid_point is 1 << (Bit_length - 1),

    % Apply the mask to the number to truncate it to the necessary number of bits
    Number_mod_mask is Number_to_truncate /\ Mask,

    % If Min_bound is less than zero (i.e., the range includes negative numbers) and Number_mod_mask is greater than or equal to the mid point,
    % interpret Number_mod_mask as a negative number in two's complement and adjust it by subtracting 2^Bit_length
    % Otherwise, use Number_mod_mask as it is
    (Min_bound < 0, Number_mod_mask >= Mid_point ->
        Result is Number_mod_mask - (1 << Bit_length)
    ;
        Result = Number_mod_mask
    ),

    Result >= Min_bound,
    Result =< Max_bound.

%% Calculates the number of bits necessary to represent a non-negative integer in binary
%% Parameters:
%%  Int: the integer that you want to represent in binary
%%  Bit_length: the number of bits required to represent the integer
bit_length(0, 0) :- !.
bit_length(Int, Bit_length) :-
    Int > 0,
    % Calculate the integer division of Int by 2 (i.e., right shift the binary representation of Int by 1 bit)
    Next is Int // 2,
    % Recursively calculate the bit length of Next
    bit_length(Next, Temp_length),
    % Add 1 to the result, because each iteration of the recursion represents one bit of Int
    Bit_length is Temp_length + 1.


util__get_breal_bounds(Breal, Min, Max) :-
    ptc_solver__variable_range(Breal, Min_bound, Max_bound),
    utils__round_real(Min_bound, 3 , Min),
    utils__round_real(Max_bound, 3 , Max).

utils__round_real(Number, Places, Result) :-
    Multiplier is 10^Places,
    Temp is Number * Multiplier,
    TempRounded is round(Temp),
    Result is TempRounded / Multiplier.

% WIP below
utils__get_number_of_pointers(Variable, Number_of_pointers) :-
    c_var__get_type(Variable, Type),
    sub_atom(Type, After, _, _, 'pointer'),
    atom_length(Type, Type_length),
    Sub_atom_length is Type_length - After,

    %Count the number of 'pointer' occurrences in the type-atom
    sub_atom(Type, After, Sub_atom_length, _, Sub_atom),
    atom_length(Sub_atom, Length),
    Number_of_pointers is Length / 7,
