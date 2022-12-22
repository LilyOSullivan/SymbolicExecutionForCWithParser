:- module(c_array).

:- export c_array__create/2.
:- export c_array__get_all/2.
:- export c_array__get_name/2.
:- export c_array__get_type/2.
:- export c_array__get_in_var/2.
:- export c_array__get_out_var/2.

%%  c_var{type,In,Out,variable_name,array_size}
:- meta_attribute(c_array, [unify:unify_c_array/2, print:print_c_array/2]).

c_array__create(Var, Out) :-
    add_attribute(Var, Out).

unify_c_array(_,Attr):-
    var(Attr).
unify_c_array(Term,Attr) :-
    % nonvar(Attr),
    compound(Attr),
    unify_term_c_array(Term,Attr).


unify_term_c_array(Value,_Attr) :-
	nonvar(Value).
unify_term_c_array(Y{AttrY},AttrX) :-
	-?->
	    unify_c_array_c_array(Y,AttrX,AttrY).

unify_c_array_c_array(_Y,AttrX,AttrY) :-
    var(AttrY),
    AttrX=AttrY.
unify_c_array_c_array(_Y,_AttrX,AttrY) :-
    nonvar(AttrY).

print_c_array(_{c_array:{_type,Val}},Out) :-
% print_c_var(_{c_array:{_Type,_Ptc_var,Val}},Out) :-
    -?->
        Out = Val.

get_c_array(_Var{C_array},Return_value) :-
    -?->
        nonvar(C_array),
        Return_value = C_array.

c_array__get_all(_Var{C_array},Out) :-
    -?->
        nonvar(C_array),
        Out = C_array.

c_array__get_type(Var,Out) :-
    get_c_array(Var,{Out,_}),
    !.

% get_ptc_var(Var,Out) :-
%     get_c_var(Var,{_,Out,_}),
%     !.

c_array__get_name(Var,Out) :-
    get_c_array(Var,{_,_,Out,_}),
    !.

c_array__get_in_var(Var,Out) :-
    get_c_array(Var,{_,{Out,_},_}),
    !.

c_array__get_out_var(Var,Out) :-
    get_c_array(Var,{_,{_,Out},_}),
    !.
