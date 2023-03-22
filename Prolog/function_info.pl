:- module(function_info).

:- export function_info__create/2.
:- export function_info__get_name/2.
:- export function_info__get_parameters/2.
:- export function_info__get_body/2.
:- export function_info__get_return_type/2.
:- export function_info__get_term/2.
:- export function_info__get_clean_function/5.

%% The module for the function_info attributed variable
%% It maintains the parsed-term for a function definition from the parser
%%
%% It holds a singular term:
%%  Function_definition in the form function_definition(Function_name, Params, Body, Return_type)
%%
%% function_info structure:
%%  function_info{function_definition(Function_name, Params, Body, Return_type)}


%% Declare function_info as an attributed variable
:- meta_attribute(function_info, [unify:unify_function_info/2, print:print_function_info/2]).

%% Used internally by ECLiPSe
%% This is a unification handler
unify_function_info(_, Attr):-
    var(Attr).
unify_function_info(Term, Attr) :-
    nonvar(Attr),
    unify_term_function_info(Term, Attr).

%% This is used for Unification, as part of the unification handler internally
%% by ECLiPSe
unify_term_function_info(Value, _Attr) :-
	nonvar(Value).
unify_term_function_info(Y{AttrY}, AttrX) :-
	-?->
	    unify_function_info_function_info(Y, AttrX, AttrY).

%% This is used for Unification, as part of the unification handler internally
%% by ECLiPSe
unify_function_info_function_info(_Y, AttrX, AttrY) :-
    var(AttrY),
    AttrX = AttrY.
unify_function_info_function_info(_Y, _AttrX, AttrY) :-
    nonvar(AttrY).

%% Used internally by ECLiPSe for printing a function_info
%% Additionally controls how the debugger displays the value
print_function_info(_{function(Function_info)}, Print_value) :-
    -?->
        Function_info = function_definition(Function_name,_,_,_),
        Print_value = function(Function_name).

%% Constructor for a function_info
function_info__create(Function_definition, Function_info_instantiated) :-
    add_attribute(Function_info_instantiated, function(Function_definition)).

%% Returns the name of the function
function_info__get_name(_Var{Function_info}, Function_name) :-
    -?->
        Function_info = function(function_definition(Function_name,_,_,_)).

%% Returns the parameters of the function
function_info__get_parameters(_Var{Function_info}, Parameters) :-
    -?->
        Function_info = function(function_definition(_, Parameters, _, _)).

%% Returns the body of the function
function_info__get_body(_Var{Function_info}, Body) :-
    -?->
        Function_info = function(function_definition(_, _, Body, _)).

%% Returns the return-type of the function
function_info__get_return_type(_Var{Function_info}, Return_type) :-
    -?->
        Function_info = function(function_definition(_, _, _, Return_type)).

function_info__get_term(_Var{Function_info}, Function_definition) :-
    -?->
        Function_info = function(Function_definition).

%% Copies the function information, while retaining any assigned values
%% such as global variables, or function attributed variables
function_info__get_clean_function(Function_info, Function_name, Parameters, Body, Return_type) :-
    function_info__get_term(Function_info, Function_definition),
    copy_term(Function_definition, Function_definition_copy, Attributed_variables_mapping),
    unify_copy_term_mapping(Attributed_variables_mapping),
    Function_definition_copy = function_definition(Function_name, Parameters, Body, Return_type).

%% Unifies attributed variables with the new copies created as a result of copy_term
unify_copy_term_mapping([]).
unify_copy_term_mapping([[Attributed_variable | Free_variable] | More_variable_mappings]) :-
    Attributed_variable = Free_variable,
    unify_copy_term_mapping(More_variable_mappings).