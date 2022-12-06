:- module(c_var).

:- export add_to_c_var/2.
:- export get_c_var/2.
:- export get_c_var_from_key/2.
:- export get_ptc_var/2.
:- export get_var_name/2.

%IDEA: This module predicates likely should have a prefix name to them
%      Eg: c_var__get_ptc_var/2


% c_var{type,ptc_variable,variable_name}
:- meta_attribute(c_var, [unify:unify_c_var/2, print:print_c_var/2]).


add_to_c_var(Var,Out) :-
    add_attribute(Var,Out).

unify_c_var(_,Attr):-
    var(Attr).
unify_c_var(Term,Attr) :-
    nonvar(Attr), %compound(Attr),
    unify_term_c_var(Term,Attr).


unify_term_c_var(Value,_Attr) :-
	nonvar(Value).
unify_term_c_var(Y{AttrY},AttrX) :-
	-?->
	unify_c_var_c_var(Y,AttrX,AttrY).

unify_c_var_c_var(_Y,AttrX,AttrY) :-
    var(AttrY), AttrX=AttrY.
unify_c_var_c_var(_Y,_AttrX,AttrY) :-
    nonvar(AttrY).

print_c_var(_{c_var:{_type,Val}},Out) :-
    -?->
        Out = Val.

get_c_var(_Var{C_var},Out) :-
    -?->
        nonvar(C_var),

        % C_var = Out. %This what a code example showed. Seems odd to me
        Out = C_var.

get_ptc_var(Var,Out) :-
    get_c_var(Var,{_,Out,_}).

get_var_name(Var,Out) :-
    get_c_var(Var,{_,_,Out}).