:- lib(ptc_solver).

:- use_module(c_var).

declaration(Type, [C_variable], Assignment) :-
    declaration__get_variable_name(C_variable, C_name),
    ptc_solver__variable([In], Type),
    c_var__create(Type, Type, In, local, C_name, C_variable),
    handle(Assignment, _),
    !.

% %% Declare an integer array
% declaration(intpointer, [C_variable]) :-
%     ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
%     ptc_solver__type(arrayType5, array, [indexType5], integer),
%     ptc_solver__variable([In], arrayType5),
%     declaration__get_variable_name(C_variable, C_name),
%     sub_string(C_name, 1, _, 0, Name_stripped), % Strip "*" from name
%     Size = 5,
%     c_array__create(int, intpointer, In, Name_stripped, Size, C_variable),
%     !.

%% Gets a clean variable name as a string from the parser-output
%% Parameters:
%%  Variable: The variable to get the name of
%%  Name: The name of the variable, as a string
%% Eg: declaration__get_variable_name(LC_x_83, Result) -> Result = "x"
declaration__get_variable_name(Variable, Name) :-
    get_var_info(Variable, name, Parser_name),
    atom_string(Parser_name, Parser_name_as_string),
    % Strip 'LC_' or 'UC_' from the variable name
    sub_string(Parser_name_as_string, 3, _, 0, Stripped_parser_name),
    utils__strip_suffix(Stripped_parser_name, Name).
