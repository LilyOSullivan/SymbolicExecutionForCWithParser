declaration(_,[]).
declaration(int,[H|T]) :-
    ptc_solver__variable([H],integer),
    declaration(int,T),
    !.

declaration(intpointer,[H|T]) :-
    % term_string(IndexType,"indexType5"),
    % term_string(ArrayType,"arrayType5"),
    ptc_solver__type(indexType5, integer, range_bounds(0, 4)),
    ptc_solver__type(arrayType5, array, [indexType5], integer),
    ptc_solver__variable([H], arrayType5),
    % ptc_solver__is_array(H),
    declaration(intpointer,T),
    !.

declaration(charpointer,[H|T]) :-
    declaration(intpointer,[H|T]).