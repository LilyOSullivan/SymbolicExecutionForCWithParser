:- lib(ptc_solver).
:- use_module(c_var).
:- use_module(c_array).

%% The below operators are used to return values the ptc_solver can understand.
:- op(1200, xfy, and_then).
:- op(1200, xfy, or_else).

%% Evaluate an expression. Failing if it is invalid, passing if it is valid.
evaluate_expression(Expression) :-
    evaluate_expression(Expression, Result),
    ptc_solver__sdl(Result),
    !.

%% Evaluate a not expression (!). Failing if it is invalid, passing if it is valid.
evaluate_expression(not(Expression)) :-
    evaluate_expression(Expression, Result),
    ptc_solver__sdl(not Result),
    !.

%% Returns the 'out' ptc_variable of a c_var
evaluate_expression(Expression, Ptc_variable) :-
    var(Expression),
    utils__find_variable(Expression, Variable),
    c_var__get_out_var(Variable, Ptc_variable).

evaluate_expression(Expression, Expression) :-
    number(Expression).

%% And Operator (&&)
evaluate_expression(andop(Left, Right), Left_Result and_then Right_result) :-
    evaluate_expression(Left, Left_Result),
    evaluate_expression(Right, Right_result).

%% Or Operator (||)
evaluate_expression(orop(Left, Right), Left_Result or_else Right_result) :-
    evaluate_expression(Left, Left_Result),
    evaluate_expression(Right, Right_result).

%% Not Operator (!)
evaluate_expression(not(Expression), not Result) :-
    evaluate_expression(Expression, Result).

%% Modulo Operator (%)
evaluate_expression(mod(Left ,Right), Left_result mod Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Not Equal (!=)
evaluate_expression(Left<>Right, Left_result <> Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Equal Boolean Operator (==)
evaluate_expression(Left==Right, Left_result=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Greater than Boolean Operator (>)
evaluate_expression(Left>Right, Left_result>Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Greater than or equal Boolean Operator (>=)
evaluate_expression(Left>=Right, Left_result>=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Less than Boolean Operator (<)
evaluate_expression(Left<Right, Left_result<Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Less than or equal Boolean Operator (<=)
evaluate_expression(Left<=Right, Left_result<=Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Subtraction (Minus) Operator for two expressions (-)
evaluate_expression(Left-Right, Left_result-Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Addition Operator (+)
evaluate_expression(Left+Right, Left_result+Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Multiplication Operator for two expressions (*)
evaluate_expression(Left*Right, Left_result*Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Division Operator (/)
evaluate_expression(Left/Right, Left_result/Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

% % Increment with ++ on the right side (Post-increment)
% % Eg: x++
evaluate_expression(post_increment(Assign_to, Increment_operation), Out) :-
    evaluate_expression(Assign_to, Out),
    evaluate_expression(Increment_operation, Increment_operation_result),
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Temp], Ptc_type),
    ptc_solver__sdl(Temp = Increment_operation_result),
    c_var__set_out_var(Assign_to, Temp).

%% Increment with ++ on the left side (Pre-increment)
%% Eg: ++x
evaluate_expression(pre_increment(Assign_to, Increment_operation), Out) :-
    evaluate_expression(Increment_operation, Increment_operation_result),
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Temp], Ptc_type),
    ptc_solver__sdl(Temp = Increment_operation_result),
    c_var__set_out_var(Assign_to, Temp),
    Out = Temp.

% %% Increment with -- on the right side (Post-decrement)
% %% Eg: x--
evaluate_expression(post_decrement(Assign_to, Decrement_operation), Out) :-
    evaluate_expression(post_increment(Assign_to, Decrement_operation),Out).

% %% Increment with -- on the left side (Pre-decrement)
% %% Eg: --x
evaluate_expression(pre_decrement(Assign_to, Decrement_operation), Out) :-
    evaluate_expression(pre_increment(Assign_to, Decrement_operation),Out).

%% Negation operator (Unary minus)
%% A value's sign being turned flipped with the minus operator
%% Eg: -x
evaluate_expression(-Expression, -Expression_result) :-
    evaluate_expression(Expression, Expression_result).

%% Assignment operator (=)
%% Eg: x = 2
evaluate_expression(assignment(Assign_to,Expression), Expression_result) :-
    evaluate_expression(Expression, Right_result),
    utils__assignment(Assign_to,Right_result,Expression_result).

%% Accessing an array element (Index)
evaluate_expression(Array[Index], element(Var, [Result])) :-
    c_array__get_out_var(Array, Var),
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index, Result).