:- use_module(c_var).

declaration(_,[]).
declaration(int,[H|T]) :-
    copy_term(H,H_copy),
    var_names(H_copy,Name),
    ptc_solver__variable([X],integer),
    add_to_c_var(C,{int,X,Name}),
    H = C,
    declaration(int,T),
    !.

declaration(intpointer,[H|T]) :-
    % term_string(IndexType,"indexType5"),
    % term_string(ArrayType,"arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([X], arrayType5),
    var_names(H,Name),
    add_to_c_var(C,{intpointer,X,Name}),
    H = C,
    % ptc_solver__is_array(H),
    declaration(intpointer,T),
    !.

declaration(charpointer,[H|T]) :-
    declaration(intpointer,[H|T]).
