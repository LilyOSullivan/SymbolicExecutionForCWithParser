:- module(c_array).
:- [utils].

:- export c_array__create/6.
:- export c_array__get_all/5.
:- export c_array__get_name/2.
:- export c_array__get_c_type/2.
:- export c_array__get_ptc_type/2.
:- export c_array__get_in_var/2.
:- export c_array__get_out_var/2.
:- export c_array__get_size/2.
:- export c_array__is_array/1.
:- export c_array__create_declaration/2.

%%  c_array{c_type,ptc_type,In,Out,variable_name,array_size}
:- meta_attribute(c_array, [unify:unify_c_array/2, print:print_c_array/2]).

%% Declare c_var as an attributed variable
c_array__create(C_type,Ptc_type, In, Var_name,Array_size, C_array_instantiated) :-
    add_attribute(C_array_instantiated, carray(C_type, Ptc_type, In, In, Var_name,Array_size)).

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
print_c_array(_{carray(_Ptc_type,_C_type,_In,_Out,Variable_name,_Size)},Display_value) :-
    -?->
        Display_value = Variable_name.

get_c_array(_Var{C_array},Return_value) :-
    -?->
        nonvar(C_array),
        Return_value = C_array.

c_array__get_all(_Var{C_array},C_type,In,Name,Size) :-
    -?->
        C_array = carray(C_type,_,In,_,Name,Size).

%% Returns the type of the c_array
c_array__get_c_type(_Var{C_array},Type) :-
    -?->
        C_array = carray(Type,_,_,_,_,_).

%% Returns the type of the c_array
c_array__get_ptc_type(_Var{C_array},Type) :-
    -?->
        C_array = carray(_, Type, _, _, _, _).

%% Returns the name in the source code of the c_array
c_array__get_name(_Var{C_array},Name) :-
    -?->
        C_array = carray(_, _, _, _,Name,_).

%% Returns the in-value of the c_array
c_array__get_in_var(_Var{C_array},In) :-
    -?->
        C_array = carray(_, _, In, _, _, _).

%% Returns the out-value of the c_array
c_array__get_out_var(_Var{C_array},Out) :-
    -?->
        C_array = carray(_, _, _, Out, _, _).

%% Returns the size of the array
c_array__get_size(_Var{C_array},Size) :-
    -?->
        C_array = carray(_, _, _, _, _, Size).

%% Checks if a variable is a c_array variable
c_array__is_array(_Var{C_array}) :-
    -?->
        C_array = carray(_, _, _, _, _, _).

c_array__create_declaration(Variable,Declaration) :-
    c_array__is_array(Variable),
    c_array__get_ptc_type(Variable,Type),
    c_array__create_declaration(Variable,Type,Declaration).

c_array__create_declaration(Variable,intpointer,Declaration) :-
    c_array__get_all(Variable,_,Ptc_in_var,Variable_name,Size),
    ptc_solver__get_array_index_elements(Ptc_in_var, Indexs),
    utils__get_all_array_inputs(Indexs, Values),
    ( foreach(Value, Values),
      foreach(Value_with_comma, Values_as_string)
      do
        term_string(Value, Value_as_string),
        concat_string([Value_as_string, ","], Value_with_comma)
    ),
    utils__join(Values_as_string, Values_joined),
    utils__strip_right_comma(Result, Result_stripped),
    term_string(Size, Size_as_string),
    sprintf(Declaration, "\t%s %s[%s] = {%s};\n", ["int", Variable_name, Size_as_string, Result_stripped]).

c_array__create_declaration(Variable,charpointer,Declaration) :-
    c_array__get_all(Variable,_,Ptc_in_var,Variable_name,Size),
    ptc_solver__get_array_index_elements(Ptc_in_var, Indexs),
    utils__get_all_array_inputs(Indexs, Values),
    ( foreach(Value, Values),
      foreach(Value_with_comma, Values_as_string)
      do
        string_codes(Value_as_string, [Value]),
        concat_string(["'", Value_as_string, "',"], Value_with_comma)
    ),
    utils__join(Values_as_string, Values_joined),
    utils__strip_right_comma(Values_joined, Result_stripped),
    term_string(Size, Size_as_string),
    sprintf(Declaration, "\t%s %s[%s] = {%s};\n", ["char", Variable_name, Size_as_string, Result_stripped]).
