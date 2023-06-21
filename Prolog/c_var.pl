:- module(c_var).

:- lib(ptc_solver).

:- export c_var__create/6.
:- export c_var__get_name/2.
:- export c_var__get_in_var/2.
:- export c_var__get_out_var/2.
:- export c_var__set_out_var/2.
:- export c_var__get_c_type/2.
:- export c_var__get_ptc_type/2.
:- export c_var__is_variable/1.
:- export c_var__get_scope/2.
:- export c_var__set_scope/2.

%% The module for the c_var attributed variable
%% It maintains meta-data about a singular non-collection variable
%% declared in the C source
%%
%% It holds the following information:
%%      Type: The variable type: Eg Int, Float, Char...
%%      In: A Ptc_solver variable of the attributed variables initial data.
%%      Out: A Ptc_solver variable that is modified upon assignment or value change.
%%      Variable_scope: The scope of the variable: Eg. Local, Global, Static...
%%      c_source_variable_name: The variable name in the C-source-code
%%
%% c_var structure:
%%  c_var{c_type,ptc_type,in,out,c_source_variable_name}


%% Declare c_var as an attributed variable
:- meta_attribute(c_var, [unify:unify_c_var/2, print:print_c_var/2]).

%% Used internally by ECLiPSe
%% This is a unification handler
unify_c_var(_, Attr):-
    var(Attr).
unify_c_var(Term, Attr) :-
    nonvar(Attr),
    unify_term_c_var(Term, Attr).

%% This is used for Unification, as part of the unification handler
unify_term_c_var(Value, _Attr) :-
	nonvar(Value).
unify_term_c_var(Y{AttrY}, AttrX) :-
	-?->
	    unify_c_var_c_var(Y, AttrX, AttrY).

%% This is used for Unification, as part of the unification handler
unify_c_var_c_var(_Y, AttrX, AttrY) :-
    var(AttrY),
    AttrX = AttrY.
unify_c_var_c_var(_Y, _AttrX, AttrY) :-
    nonvar(AttrY).

%% Used internally by ECLiPSe for printing a c_var
%% Additionally controls how the debugger displays the value
print_c_var(_{cvar(_CType,_PTCType,_Variable_scope , _In, _Out, Name)}, Print_value) :-
    -?->
        Print_value = cvar(Name).

%% Constructor for a c_var
c_var__create(C_type, Ptc_type, Ptc_variable_in, Variable_scope, Var_name, C_var_instantiated) :-
    add_attribute(C_var_instantiated, cvar(C_type, Ptc_type, Ptc_variable_in, Ptc_variable_in, Variable_scope, Var_name)).

%% Returns the c-type of the c_var
c_var__get_c_type(_Var{C_var}, C_type) :-
    -?->
        C_var = cvar(C_type, _, _, _, _, _).

%% Returns ptc type of the c_var
c_var__get_ptc_type(_Var{C_var}, Ptc_type) :-
    -?->
        C_var = cvar(_, Ptc_type, _, _, _, _).

%% Returns the name in the source code of the c_var
c_var__get_name(_Var{C_var}, Name) :-
    -?->
        C_var = cvar(_, _, _, _, _, Name).

%% Returns the in-value of the c_var
c_var__get_in_var(_Var{C_var}, In_var) :-
    -?->
        C_var = cvar(_, _, In_var, _, _, _).

%% Returns the out-value of the c_var
c_var__get_out_var(_Var{C_var}, Out_var) :-
    -?->
        C_var = cvar(_, _, _, Out_var, _, _).

%% Sets the out-value of the c_var
c_var__set_out_var(_Var{C_var}, New_out_variable) :-
    -?->
        setarg(4, C_var, New_out_variable).

c_var__get_scope(_Var{C_var}, Scope) :-
    -?->
        C_var = cvar(_, _, _, _, Scope, _).

c_var__set_scope(_Var{C_var}, New_scope) :-
    -?->
        setarg(5, C_var, New_scope).

%% Passes if the variable is a c_var
%% Fails otherwise
c_var__is_variable(_Var{C_var}) :-
    -?->
        C_var = cvar(_, _, _, _, _, Name),
        nonvar(Name).
