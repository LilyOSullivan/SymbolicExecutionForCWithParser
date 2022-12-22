:- module(declaration).

:- export declaration/2.

:- use_module(c_var).
:- use_module(c_array).
:- use_module(ptc_solver).
:- use_module(utils).

declaration(_, []).
declaration(int, [H|T]) :-
    copy_term(H, H_copy),
    utils__var_name(H_copy, Name),
    ptc_solver__variable([In], integer),
    % ptc_solver__variable([Out], integer),
    % ptc_solver__sdl(eq_cast(Out, In)),
    c_var__create(int, In, Name, C_var_instantiated),
    H = C_var_instantiated,
    declaration(int, T),
    !.

declaration(intpointer, [H|T]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(H, H_copy),
    utils__var_name(H_copy, Name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Name, 1, _, 0, Name_stripped), % Strip "*" from name


    %HACK: This would ideally be suspended if variable
    Size = 5,

    c_array__create(C, {intpointer, {In, Out}, Name_stripped, Size}),
    H = C,
    % ptc_solver__is_array(H),
    declaration(intpointer, T),
    !.

declaration(charpointer, [H|T]) :-
    % term_string(IndexType, "indexType5"),
    % term_string(ArrayType, "arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], char),
    ptc_solver__variable([In], arrayType5),
    ptc_solver__variable([Out], arrayType5),
    copy_term(H, H_copy),
    utils__var_name(H_copy, Name),
    %TODO: This might be a 'mistake' from the parser. Eg int *buf vs int* buf
    sub_string(Name, 1, _, 0, Name_stripped), % Strip "*" from name

    %HACK: This would ideally be suspended if variable
    Size = 5,

    c_array__create(C, {charpointer, {In, Out}, Name_stripped, Size}),
    H = C,
    % ptc_solver__is_array(H),
    declaration(intpointer, T),
    !.
