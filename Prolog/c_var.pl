:- module(c_var).

:- export c_var__create/5.
:- export c_var__get_name/2.
:- export c_var__get_in_var/2.
:- export c_var__get_out_var/2.
:- export c_var__set_out_var/2.
:- export c_var__get_all/4.
:- export c_var__get_c_type/2.
:- export c_var__get_ptc_type/2.
:- export c_var__is_variable/1.
:- export c_var__create_declaration/2.


%% The module for the c_var attributed variable
%% It maintains meta-data about a singular non-collection variable
%% declared in the C source
%%
%% It holds the following information:
%%      Type: The variable type: Eg Int, Float, Char...
%%      In: A Ptc_solver variable of the attributed variables initial data.
%%      Out: A Ptc_solver variable that is modified upon assignment or value change.
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
print_c_var(_{cvar(_Type, _In, _Out, Name)}, Print_value) :-
    -?->
        Print_value = cvar(Name).

%% Constructor for a c_var
c_var__create(C_type, Ptc_type,Ptc_variable_in, Var_name, C_var_instantiated) :-
    add_attribute(C_var_instantiated, cvar(C_type, Ptc_type, Ptc_variable_in, Ptc_variable_in, Var_name)).

c_var__get_all(_Var{C_var}, C_type, In, Name) :-
    -?->
        C_var = cvar(C_type,_, In, _, Name).

%% Returns the c-type of the c_var
c_var__get_c_type(_Var{C_var}, Type) :-
    -?->
        C_var = cvar(Type, _,_, _, _).

%% Returns ptc type of the c_var
c_var__get_ptc_type(_Var{C_var}, Type) :-
    -?->
        C_var = cvar(_, Type,_, _, _).

%% Returns the name in the source code of the c_var
c_var__get_name(_Var{C_var}, Name) :-
    -?->
        C_var = cvar(_, _, _, _, Name).

%% Returns the in-value of the c_var
c_var__get_in_var(_Var{C_var}, In_var) :-
    -?->
        C_var = cvar(_, _, In_var, _, _).

%% Returns the out-value of the c_var
c_var__get_out_var(_Var{C_var}, Out_var) :-
    -?->
        C_var = cvar(_, _, _, Out_var, _).

%% Sets the out-value of the c_var
c_var__set_out_var(_Var{C_var}, Value) :-
    -?->
        setarg(4, C_var, Value).

%% Passes if the variable is a c_var
%% Fails otherwise
c_var__is_variable(_{cvar(C_var)}) :-
    -?->
        C_var = cvar(_, _, _, _, _).

c_var__create_declaration(Variable,Declaration) :-
    c_var__is_variable(Variable),

    c_var__get_c_type(Variable,Type),
    c_var__create_declaration(Variable,Type,Declaration).

c_var__create_declaration(Variable,int,Declaration) :-
    c_var__get_all(Variable, _, Ptc_in_var, Var_name),
    term_string(Ptc_in_var, Value),
    sprintf(Declaration, "\t%s %s = %s;\n", [int, Var_name, Value]).