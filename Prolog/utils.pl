:- lib(ptc_solver).

%% is_static_declaration/1
%% is_static_declaration(+Declaration)
%% Checks if a declaration is a for a static variable
%% Parameters:
%%  Declaration: The declaration to check if it is static
is_static_declaration(declaration(Functor, [Variable], _)) :-
    atom(Functor),
    var(Variable),
    sub_atom(Functor, 0, _, _, 'static_').

%% is_static_declared/1
%% is_static_declared(+Declaration)
%% Checks if a declaration is a for a static variable that has already been declared
%% Parameters:
%%  Declaration: The declaration to check if it is static and declared
is_static_declared(declaration(Functor, [Variable], _)) :-
    is_static_declaration(declaration(Functor, [Variable], _)),
    c_var__is_variable(Variable).

%% is_static_undeclared/1
%% is_static_undeclared(+Declaration)
%% Checks if a declaration is a for a static variable that has not been declared
%% Parameters:
%%  Declaration: The declaration to check if it is static and undeclared
is_static_undeclared(declaration(Functor, [Variable], _)) :-
    is_static_declaration(declaration(Functor, [Variable], _)),
    not c_var__is_variable(Variable).

%% declare_static_variables/1
%% declare_static_variables(+Statements)
%% Checks if a list of statements contains any static variables that have not been declared, and declares them
%% Parameters:
%%  Statements: The list of statements to check for static variables
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

%% Removes the last character if it is a comma
%% Parameters:
%%  String_with_comma: The string to remove the comma from
%%  String_without_comma: The string without the comma
utils__strip_right_comma(String_with_comma, String_without_comma) :-
    (sub_string(String_with_comma, _, 1, 0, ",") ->
        sub_string(String_with_comma, 0, _, 1, String_without_comma)
    ;
        String_without_comma = String_with_comma
    ).

%% utils__string_contains/2
%% utils__string_contains(+Original, +Substring)
%% Check if a string contains a substring
%% Parameters:
%%  Original:The string to check if it contains the substring
%%  Substring: The string to be checked if contained within the first parameter
utils__string_contains(Original, Substring) :-
    once sub_string(Original, _, _, _, Substring).

%% Assigns a value to a variable, with a return of the assigned value
%% Parameters:
%%  Assign_to: The variable to assign to
%%  Value: The value to assign
%%  Assigned_value: The value assigned that has been assigned
%% Eg: utils__assignment(Assign_to{"x"}, 5, Result) -> Result = 5
utils__assignment(Assign_to, Value, Assigned_value) :-
    utils__get_appropriate_cvar_type(Assign_to, Type),
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
    utils__demotion(Value_to_assign, Type, Value_to_assign_demoted),
    ptc_solver__sdl(eq_cast(Assigned_value, Value_to_assign_demoted)),
    c_var__set_out_var(Assign_to, Assigned_value).

%% utils__get_appropriate_cvar_type/2
%% utils__get_appropriate_cvar_type(+Variable, -Type)
%% If c_var is a pointer type, returns an int type, otherwise returns
%% the type of the c_var. This is for the ptc_solver to declare pointers as integers.
%% Parameters:
%%  Variable: The c_var to get the type of
%%  Type: The type of the c_var for the ptc_solver
utils__get_appropriate_cvar_type(Variable, pointer) :-
    c_var__is_pointer(Variable),
    !.
utils__get_appropriate_cvar_type(Variable, Type) :-
    c_var__get_type(Variable, Type).

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

%% utils__error_if_false/2
%% utils__error_if_false(+Goal, +Error_message)
%% This predicate takes a Goal and an Error_message as input. It evaluates the Goal and if it fails, it prints an error message and aborts the program.
%% Parameters:
%%  Goal: The goal to be evaluated.
%%  Error_message: The error message to be printed if the Goal fails.
utils__error_if_false(Goal, Error_message) :-
    (Goal ->
        true
    ;
        concat_string(["Error: ", Error_message], Error_message_complete),
        writeln(Error_message_complete),
        abort
    ).

%% utils__demotion/3
%% utils__demotion(+Number_to_demote, +Type, -Result)
%% Demotions a number to fit in a range.
%% Parameters:
%%  Number_to_demote: the value to be demoted
%%  Type: the type to demote to
%%  Result: the final truncated number
%% ----------------------------------
%% From the C standard:
%% 6.3.1.3 Signed and unsigned integers - Clause 2
%%      "the value is converted by repeatedly adding or subtracting one more
%%      than the maximum value that can be represented in the new type until the value
%%      is in the range of the new type."
%% https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
%% ----------------------------------
utils__demotion(Number_to_demote, Type, Result) :-
    get_type_information(Type, _Byte_size, Min_bound, Max_bound),
    utils__demotion(Number_to_demote, Min_bound, Max_bound, Result).
utils__demotion(Number_to_demote, Min_bound, Max_bound, Result) :-
    Range = Max_bound - Min_bound + 1,
    (ptc_solver__sdl((Number_to_demote) > Max_bound) ->
        utils__demotion((Number_to_demote) - Range, Min_bound, Max_bound, Result)
    ;
    ptc_solver__sdl((Number_to_demote) < Min_bound) ->
        utils__demotion((Number_to_demote) + Range, Min_bound, Max_bound, Result)
    ;
        Result = Number_to_demote
    ).

util__get_breal_bounds(Breal, Min, Max) :-
    ptc_solver__variable_range(Breal, Min_bound, Max_bound),
    utils__round_real(Min_bound, 3 , Min),
    utils__round_real(Max_bound, 3 , Max).

utils__round_real(Number, Places, Result) :-
    Multiplier is 10^Places,
    Temp is Number * Multiplier,
    TempRounded is round(Temp),
    Result is TempRounded / Multiplier.

