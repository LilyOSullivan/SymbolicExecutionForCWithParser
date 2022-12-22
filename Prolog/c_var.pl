:- module(c_var).

:- export c_var__create/2.
:- export c_var__get_all/2.
:- export c_var__get_name/2.
:- export c_var__get_type/2.
:- export c_var__get_in_var/2.
:- export c_var__get_out_var/2.

%% if int/char:
%%  c_var{type,{In,Out},variable_name}
:- meta_attribute(c_var, [unify:unify_c_var/2, print:print_c_var/2]).

% get_attribute(_{Name:Attribute}, A) :-
%     -?->
%         A = Attribute.

c_var__create(C_var,Out) :-
    add_attribute(C_var,Out).

unify_c_var(_,Attr):-
    var(Attr).
unify_c_var(Term,Attr) :-
    nonvar(Attr),
    % compound(Attr),
    unify_term_c_var(Term,Attr).


unify_term_c_var(Value,_Attr) :-
	nonvar(Value).
unify_term_c_var(Y{AttrY},AttrX) :-
	-?->
	    unify_c_var_c_var(Y,AttrX,AttrY).

unify_c_var_c_var(_Y,AttrX,AttrY) :-
    var(AttrY),
    AttrX=AttrY.
unify_c_var_c_var(_Y,_AttrX,AttrY) :-
    nonvar(AttrY).

print_c_var(_{c_var:{_type,_in_out,Name}},Out) :-
% print_c_var(_{c_var:{_Type,_Ptc_var,Val}},Out) :-
    -?->
        Out = Name.

get_c_var(_Var{C_var},Out) :-
    -?->
        nonvar(C_var),
        Out = C_var.

c_var__get_type(C_var,Out) :-
    get_c_var(C_var,{Out,_,_}), %FIXME: More than one underscore should not be needed here
    !.

c_var__get_name(C_var,Out) :-
    get_c_var(C_var,{_,_,Out,_}),
    !.

c_var__get_name(C_var,Out) :-
    get_c_var(C_var,{_,_,Out}),
    !.

c_var__get_in_var(C_var,Out) :-
    get_c_var(C_var,{_,{Out,_},_}),
    !.

c_var__get_out_var(C_var,Out) :-
    get_c_var(C_var,{_,{_,Out},_}),
    !.
