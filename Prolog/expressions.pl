% IDEA: There likely needed to be a handling of "true" and "false", as C
%       Possibly true = 1, false = 0?

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

% HACK: If this is not first, it will infinitely recurse into andop with get_sign, not sure why
evaluate_expression(Expression,Out) :-
    get_ptc_var(Expression,Out).

evaluate_expression(andop(Left,Right),Out) :-
    evaluate_expression(Left,Left_Result),
    evaluate_expression(Right,Right_Result),
    Out = (Left_Result and_then Right_Result).

evaluate_expression(orop(Left,Right),Out) :-
    evaluate_expression(Left,Left_Result),
    evaluate_expression(Right,Right_Result),
    Out = (Left_Result or_else Right_Result).

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
    Out = (Left_result>Right_result).

evaluate_expression(Left<Right,Out) :-
    evaluate_expression(Left,Left_result),
    evaluate_expression(Right,Right_result),
    Out = (Left_result<Right_result).

evaluate_expression(Array[Index],Out) :-
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index,Result),
    Out = element(Array,[Result]). % IDEA: possibly suspend/defer this, if variable

evaluate_expression(Expression,Out) :-
    (
        number(Expression) ->
            Out = Expression
                ;
        ptc_solver__is_integer(Expression) ->
            Out = Expression
                ;
        ptc_solver__sdl(Expression) -> % Default to ptc_solver__sdl
            Out = true  %QUESTION: What should be returned here?
    ).


