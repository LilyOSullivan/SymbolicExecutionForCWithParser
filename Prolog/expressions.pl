% IDEA: There likely needed to be a handling of "true" and "false", as C
%       Possibly true = 1, false = 0?

%FIXME: utils__evaluate_to_int will not work for floats

:- module(expressions).

:- export evaluate_expression/1.
:- export evaluate_expression/2.

:- lib(ptc_solver).
:- use_module(c_var).
:- use_module(c_array).
:- use_module(utils).


:- op(1200,xfy,and_then).
% :- op(1200,xfy,and).
:- op(1200,xfy,or_else).
% :- op(1200,xfy,or).

evaluate_expression(Expression) :-
    evaluate_expression(Expression,Result),
    ptc_solver__sdl(Result),
    !.

evaluate_expression(not(Expression)) :-
    evaluate_expression(Expression,Result),
    ptc_solver__sdl(not Result),
    !.

% HACK: If this is not first, it will infinitely recurse into andop with get_sign.
%       I think this might be a tracer-visual bug

evaluate_expression(Expression,Out) :-
    c_var__get_out_var(Expression,Out).

evaluate_expression(andop(Left,Right),Out) :-
    evaluate_expression(Left,Left_Result),
    evaluate_expression(Right,Right_result),
    Out = (Left_Result and_then Right_result).

evaluate_expression(orop(Left,Right),Out) :-
    evaluate_expression(Left,Left_Result),
    evaluate_expression(Right,Right_result),
    Out = (Left_Result or_else Right_result).

evaluate_expression(not(Expression),Out) :-
    evaluate_expression(Expression,Result),
    % Result = (not Out).
    Out = (not Result).

evaluate_expression(Left==Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result=Right_result).

evaluate_expression(Left>Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result<Right_result).

evaluate_expression(Left<Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result<Right_result).

evaluate_expression(Left-Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    utils__evaluate_to_int(Left_result-Right_result,Result),
    Out = Result.

evaluate_expression(Left+Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    % utils__evaluate_to_int(Left_result+Right_result,Result),
    % Out = Result.
    Out = (Left_result+Right_result).


evaluate_expression(Left*Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result*Right_result).

evaluate_expression(Left/Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result/Right_result).

evaluate_expression(Array[Index],Out) :-
    c_array__get_out_var(Array,Var),
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index,Result),
    Out = element(Var,[Result]).

evaluate_expression(Expression,Out) :-
    (
        number(Expression) ->
            Out = Expression
                ;
        ptc_solver__is_integer(Expression) -> %TODO: I think this check if now unneeded
            Out = Expression
            ;
        (
            ptc_solver__sdl(Expression) -> % Default to ptc_solver__sdl
                Out = 1
            ;
                Out = 0
        )
    ).


