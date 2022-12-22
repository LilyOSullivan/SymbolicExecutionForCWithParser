:- module(c_var).

:- lib(ptc_solver).

:- export c_var__create/4.
:- export c_var__get_name/2.
:- export c_var__get_type/2.
:- export c_var__get_in_var/2.
:- export c_var__get_out_var/2.
:- export c_var__set_out_var/2.
:- export c_var__get_all/4.

%% c_var structure:
%%  c_var{type,in,out,c_source_variable_name}

%% Declare c_var as an attributed variable
:- meta_attribute(c_var, [unify:unify_c_var/2, print:print_c_var/2]).

%% Used internally by ECLiPSe
%% This is a unification handler
unify_c_var(_,Attr):-
    var(Attr).
unify_c_var(Term,Attr) :-
    nonvar(Attr),
    unify_term_c_var(Term,Attr).

%% This is used for Unification, as part of the unification handler
unify_term_c_var(Value,_Attr) :-
	nonvar(Value).
unify_term_c_var(Y{AttrY},AttrX) :-
	-?->
	    unify_c_var_c_var(Y,AttrX,AttrY).

%% This is used for Unification, as part of the unification handler
unify_c_var_c_var(_Y,AttrX,AttrY) :-
    var(AttrY),
    AttrX=AttrY.
unify_c_var_c_var(_Y,_AttrX,AttrY) :-
    nonvar(AttrY).

%% Used internally by ECLiPSe for printing a c_var
%% Additionally controls how the debugger displays the value
print_c_var(_{c_var:{_type,_in,_out,Name}},Print_value) :-
    -?->
        Print_value = Name.

%% Constructor for a c_var
c_var__create(Type,In,Var_name,C_var_instantiated) :-
    ptc_solver__variable([Out],integer),
    ptc_solver__sdl(Out=In),
    add_attribute(C_var_instantiated,{Type,In,Out,Var_name}).

c_var__get_all(_Var{C_var},Type,In,Name) :-
    -?->
        C_var = {Type,In,_,Name}.

%% Returns the type of the c_var
c_var__get_type(_Var{C_var},Type) :-
    -?->
        C_var = {Type,_,_,_}.

%% Returns the name in the source code of the c_var
c_var__get_name(_Var{C_var},Name) :-
    -?->
        C_var = {_,_,_,Name}.

%% Returns the in-value of the c_var
c_var__get_in_var(_Var{C_var},In_var) :-
    -?->
        C_var = {_,In_var,_,_}.

%% Returns the out-value of the c_var
c_var__get_out_var(_Var{C_var},Out_var) :-
    -?->
        C_var = {_,_,Out_var,_}.

%% Returns the out-value of the c_var
c_var__set_out_var(_Var{C_var},Value) :-
    -?->
        setarg(3,C_var,Value).
        % c_var__get_out_var(C_var,Out_var),
        % Out_var = Value.

