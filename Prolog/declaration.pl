:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).

%% Handles a stop condition for the recursive declaration/2 predicate
declaration(_, []).

%% Declare an integer variable
declaration(int, [C_variable | Rest]) :-
    get_var_info(C_variable, name, Ptc_name),
    var_names(Ptc_name, C_name),
    ptc_solver__variable([In], integer),
    c_var__create(int, integer, In, C_name, C_variable),
    declaration(int, Rest),
    !.

declaration(char, [C_variable | Rest]) :-
    get_var_info(C_variable, name, Ptc_name),
    var_names(Ptc_name, C_name),
    ptc_solver__variable([In], char),
    c_var__create(char, char, In, C_name, C_variable),
    declaration(char, Rest),
    !.

%% Declare an integer array
declaration(intpointer, [C_variable | Rest]) :-
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([In], arrayType5),
    copy_term(C_variable, Variable_copy),
    var_names(Variable_copy, Variable_name),
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(int,intpointer, In, Name_stripped, Size, C_variable),
    declaration(intpointer, Rest),
    !.

%% Declare a character array
declaration(charpointer, [C_variable | Rest]) :-
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], char),
    ptc_solver__variable([In], arrayType5),
    copy_term(C_variable, Variable_copy),
    var_names(Variable_copy, Variable_name),
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(char,charpointer, In, Name_stripped, Size, C_variable),
    declaration(intpointer, Rest),
    !.
