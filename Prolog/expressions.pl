% IDEA: There likely needed to be a handling of "true" and "false", as C
%       Possibly true = 1, false = 0?

:- module(expressions).

:- export evaluate_expression/1.
:- export evaluate_expression/2.

:- lib(ptc_solver).
:- use_module(c_var).
:- use_module(c_array).
% :- ['utils'].


:- op(1200, xfy, and_then).
% :- op(1200, xfy, and).
:- op(1200, xfy, or_else).
% :- op(1200, xfy, or).

%% Evaluate an expression. Failing if it is invalid, passing if it is valid.
evaluate_expression(Expression) :-
    evaluate_expression(Expression, Result),
    ptc_solver__sdl(Result),
    !.

%% Evaluate a not expression. Failing if it is invalid, passing if it is valid.
evaluate_expression(not(Expression)) :-
    evaluate_expression(Expression, Result),
    ptc_solver__sdl(not Result),
    !.

evaluate_expression(Expression, Ptc_variable) :-
    var(Expression),
    c_var__get_out_var(Expression, Ptc_variable).

evaluate_expression(Expression, Out) :-
    number(Expression),
    Out = Expression.

evaluate_expression(andop(Left, Right), Left_Result and_then Right_result) :-
    evaluate_expression(Left, Left_Result),
    evaluate_expression(Right, Right_result).

evaluate_expression(orop(Left, Right), Left_Result or_else Right_result) :-
    evaluate_expression(Left, Left_Result),
    evaluate_expression(Right, Right_result).

evaluate_expression(not(Expression), not Result) :-
    evaluate_expression(Expression, Result).

evaluate_expression(mod(Left ,Right), Left_result mod Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left==Right, Left_result=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left>Right, Left_result>Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left>=Right, Left_result>=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left<Right, Left_result<Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left<=Right, Left_result<=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left-Right, Left_result-Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left+Right, Left_result+Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left*Right, Left_result*Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(Left/Right, Left_result/Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(post_increment(Assign_to, Increment_operation), Assign_to) :-
    evaluate_expression(Assign_to, Assign_to_result),
    evaluate_expression(Increment_operation, Increment_operation_result),
    % Out = Assign_to,
    ptc_solver__sdl(Assign_to_result = Increment_operation_result).

evaluate_expression(pre_increment(Assign_to, Increment_operation), Assign_to) :-
    evaluate_expression(Assign_to, Assign_to_result),
    evaluate_expression(Increment_operation, Increment_operation_result),
    ptc_solver__sdl(Assign_to_result = Increment_operation_result).
    % Out = Assign_to.

evaluate_expression(Left/Right, Left_result/Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

evaluate_expression(-Expression, -Expression_result) :-
    evaluate_expression(Expression, Expression_result).

evaluate_expression(Array[Index], element(Var, [Result])) :-
    c_array__get_out_var(Array, Var),
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index, Result).
    % Out = element(Var, [Result]).


