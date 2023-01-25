:- module(c_array).

:- export c_array__create/5.
:- export c_array__get_all/2.
:- export c_array__get_name/2.
:- export c_array__get_type/2.
:- export c_array__get_in_var/2.
:- export c_array__get_out_var/2.
:- export c_array__get_size/2.
:- export c_array__is_array/1.

%%  c_array{type,In,Out,variable_name,array_size}
:- meta_attribute(c_array, [unify:unify_c_array/2, print:print_c_array/2]).

%% Declare c_var as an attributed variable
c_array__create(Type, In, Var_name,Array_size, C_array_instantiated) :-
    add_attribute(C_array_instantiated, carray(Type, In, In, Var_name,Array_size)).

%% Used internally by ECLiPSe
%% This is a unification handler
unify_c_array(_,Attr):-
    var(Attr).
unify_c_array(Term,Attr) :-
    % nonvar(Attr),
    compound(Attr),
    unify_term_c_array(Term,Attr).

%% This is used for Unification, as part of the unification handler
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

%% Used internally by ECLiPSe for printing a c_array
%% Additionally controls how the debugger displays the value
print_c_array(_{carray(_type,_In,_Out,Variable_name,_Size)},Display_value) :-
    -?->
        Display_value = Variable_name.

get_c_array(_Var{C_array},Return_value) :-
    -?->
        nonvar(C_array),
        Return_value = C_array.

c_array__get_all(_Var{C_array},Out) :-
    -?->
        nonvar(C_array),
        Out = C_array.

%% Returns the type of the c_array
c_array__get_type(Var,Out) :-
    get_c_array(Var,{Out,_}),
    !.

% get_ptc_var(Var,Out) :-
%     get_c_var(Var,{_,Out,_}),
%     !.

%% Returns the name in the source code of the c_array
c_array__get_name(Var,Out) :-
    get_c_array(Var,{_,_,Out,_}),
    !.

%% Returns the in-value of the c_array
c_array__get_in_var(Var,Out) :-
    get_c_array(Var,{_,{Out,_},_}),
    !.

%% Returns the out-value of the c_array
c_array__get_out_var(Var,Out) :-
    get_c_array(Var,{_,{_,Out},_}),
    !.

%% Returns the size of the array
c_array__get_size(Var,Size) :-
    get_c_array(Var,{_,{_,_},_,Size}),
    !.

%% Checks if a variable is a c_array variable
c_array__is_array(_{carray(_)})
