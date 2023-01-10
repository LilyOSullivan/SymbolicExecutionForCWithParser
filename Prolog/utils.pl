:- module(utils).

:- export utils__var_name/2.
:- export utils__get_all_array_inputs/2.
:- export utils__evaluate_to_int/2.
:- export utils__ptc_type/2.
:- dynamic utils__var_name/2.
:- dynamic var_names/1.

:- lib(ptc_solver).

%HACK: The function below was greatly hacked. It needs to be fixed up.
%% Reads from the .names file
utils__var_name(Prolog_var_name, C_var_name) :-
    retract(names_file(Names_filename))@main,
    !,
    compile(Names_filename),
    asserta(names_file(Names_filename))@main,
    !,
    var_names(Prolog_var_name, C_var_name),
    !.

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