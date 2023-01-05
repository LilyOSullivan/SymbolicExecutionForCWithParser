:- module(declaration).

:- export declaration/2.

:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).
:- use_module(utils).

%% Handles a stop condition for the recursive declaration/2 predicate
declaration(_, []).

%% Declare an integer variable
declaration(int, [Variable|Rest]) :-
    copy_term(Variable, Variable_copy),
    utils__var_name(Variable_copy, Variable_name),
    ptc_solver__variable([In], integer),
    c_var__create(int, In, Variable_name, C_var_instantiated),
    Variable = C_var_instantiated,
    declaration(int, Rest),
    !.

%% Declare an integer array
declaration(intpointer, [Variable|Rest]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(Variable, Variable_copy),
    utils__var_name(Variable_copy, Variable_name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(C_var, {intpointer, {In, Out}, Name_stripped, Size}),
    Variable = C_var,
    declaration(intpointer, Rest),
    !.

%% Declare a character array
declaration(charpointer, [Variable|Rest]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], char),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(Variable, Variable_copy),
    utils__var_name(Variable_copy, Variable_name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(C, {charpointer, {In, Out}, Name_stripped, Size}),
    Variable = C,
    declaration(intpointer, Rest),
    !.
