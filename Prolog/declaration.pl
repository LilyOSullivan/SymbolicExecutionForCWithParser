:- lib(ptc_solver).

:- use_module(c_var).
:- use_module(c_array).

%% Handles a stop condition for the recursive declaration/2 predicate
declaration(_, []).

%% Declare an integer variable
declaration(int, [C_variable|Rest]) :-
    copy_term(C_variable, Variable_copy),
    % FIXME: Variable name is matching to the first as free variables
    var_names(Variable_copy, Variable_name),
    ptc_solver__variable([In], integer),
    c_var__create(int, integer, In, Variable_name, C_variable),
    declaration(int, Rest),
    !.

%% Declare an integer array
declaration(intpointer, [C_variable|Rest]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(C_variable, Variable_copy),
    var_names(Variable_copy, Variable_name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(C_variable, {intpointer, {In, Out}, Name_stripped, Size}),
    declaration(intpointer, Rest),
    !.

%% Declare a character array
declaration(charpointer, [C_variable|Rest]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], char),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(C_variable, Variable_copy),
    var_names(Variable_copy, Variable_name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Variable_name, 1, _, 0, Name_stripped), % Strip "*" from name
    Size = 5,
    c_array__create(C_variable, {charpointer, {In, Out}, Name_stripped, Size}),
    declaration(intpointer, Rest),
    !.
