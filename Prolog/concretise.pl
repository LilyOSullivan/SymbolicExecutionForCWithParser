% From Eileens Code
get_all_array_inputs([], []).
get_all_array_inputs( [(_, Value)|Rest], [Value|Rest2]) :-
	get_all_array_inputs(Rest, Rest2).

concretise([]).
concretise([declaration(intpointer,[H|T])|TT]) :-
	ptc_solver__get_array_index_elements(H, Indexs),
	get_all_array_inputs(Indexs, Out),
    ptc_solver__label_integers([Out]),
    !,
    concretise(T), % This labels single-line declarations: int a,b;
    concretise(TT).

concretise([declaration(int,[H|T])|TT]) :-
    ptc_solver__label_integers([H]),
    !,
    concretise(T),
    concretise(TT).

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