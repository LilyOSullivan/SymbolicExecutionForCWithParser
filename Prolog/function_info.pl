:- module(function_info).

:- export function_info__create/5.
:- export function_info__get_name/2.
:- export function_info__get_parameters/2.
:- export function_info__get_body/2.
:- export function_info__get_return_type/2.
:- export function_info__get_all/5.

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
%%  c_var{function_name, parameters, body, return_type}


%% Declare function_info as an attributed variable
:- meta_attribute(function_info, [unify:unify_function_info/2, print:print_function_info/2]).

%% Used internally by ECLiPSe
%% This is a unification handler
unify_function_info(_, Attr):-
    var(Attr).
unify_function_info(Term, Attr) :-
    nonvar(Attr),
    unify_term_function_info(Term, Attr).

%% This is used for Unification, as part of the unification handler
unify_term_function_info(Value, _Attr) :-
	nonvar(Value).
unify_term_function_info(Y{AttrY}, AttrX) :-
	-?->
	    unify_function_info_function_info(Y, AttrX, AttrY).

%% This is used for Unification, as part of the unification handler
unify_function_info_function_info(_Y, AttrX, AttrY) :-
    var(AttrY),
    AttrX = AttrY.
unify_function_info_function_info(_Y, _AttrX, AttrY) :-
    nonvar(AttrY).

%% Used internally by ECLiPSe for printing a c_var
%% Additionally controls how the debugger displays the value
print_function_info(_{function(Function_name, _Params, _Body, _Return_type)}, Print_value) :-
    -?->
        Print_value = function(Function_name).

%% Constructor for a c_var
function_info__create(Function_name, Params, Body, Return_type, Function_info_instantiated) :-
    add_attribute(Function_info_instantiated, function(Function_name, Params, Body, Return_type)).

%% Returns the name of the function
function_info__get_name(_Var{Function_info}, Function_name) :-
    -?->
        Function_info = function(Function_name, _, _, _).

%% Returns the parameters of the function
function_info__get_parameters(_Var{Function_info}, Parameters) :-
    -?->
        Function_info = function(_, Parameters, _, _).

%% Returns the body of the function
function_info__get_body(_Var{Function_info}, Body) :-
    -?->
        Function_info = function(_, _, Body, _).

%% Returns the return-type of the function
function_info__get_body(_Var{Function_info}, Return_type) :-
    -?->
        Function_info = function(_, _, _, Return_type).

%% Returns all information about the function
function_info__get_all(_Var{Function_info}, Function_name, Params, Body, Return_type) :-
    -?->
        Function_info = function(Function_name, Params, Body, Return_type).
