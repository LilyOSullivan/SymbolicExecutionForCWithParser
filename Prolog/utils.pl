:- lib(ptc_solver).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

utils__evaluate_to_int(Expression, Out) :-
    ptc_solver__variable([Out], integer),
    ptc_solver__sdl(Out = Expression),
    % ptc_solver__label_integers([Out]),
    !. % FIXME: Check if this leaves a choice-point. Cut might not be needed

utils__ptc_type(int, integer).