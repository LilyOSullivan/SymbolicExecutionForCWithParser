% From Eileen's Code
get_all_array_inputs([], []).
get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	get_all_array_inputs(Rest, Rest2).

% The cut is needed here. Otherwise Prolog attempts to match it with other concretise predicates
concretise([void]) :- !.
concretise([]).
concretise([declaration(intpointer,[H|_])|T]) :-
	ptc_solver__get_array_index_elements(H, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T).

concretise([declaration(charpointer,[H|_])|T]) :-
    % Treating same as ints
    % Can call: concretise(char(Out),Result) to get 'char' result
    ptc_solver__get_array_index_elements(H, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    % concretise(char(Out),Result),
    !,
    concretise(T).

concretise([declaration(int,[H|_])|T]) :-
    ptc_solver__label_integers([H]),
    !,
    concretise(T).

% concretise(int(X),Out) :-
    % ptc_solver__label_integers([X]),
    % !.

concretise(char(X),Out) :-
    % ptc_solver__label_integers([X]),
    string_codes(Out,[X]),
    !.

concretise(X,Type,Out) :-
    (
        Type == int ->
            Out = X
            ;
        Type == char ->
            concretise(char(X),Out)
    ).