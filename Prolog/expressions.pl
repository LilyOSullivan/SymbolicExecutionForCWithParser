:- lib(ptc_solver).

:- use_module(c_array).
:- use_module(c_var).

%% The below operators are used to return values the ptc_solver can understand.
:- op(1200, xfy, and_then).
:- op(1200, xfy, or_else).

%% Evaluate an expression. Failing if it is invalid, passing if it is valid.
evaluate_expression(Expression) :-
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(Expression_result),
    !.

%% Evaluate a not expression (!). Failing if it is invalid, passing if it is valid.
evaluate_expression(not(Expression)) :-
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(not Expression_result),
    !.

%% Returns the 'out' ptc_variable of a c_var
evaluate_expression(Expression, Ptc_variable) :-
    var(Expression),
    c_var__get_out_var(Expression, Ptc_variable).

%% Returns a number-constant
%% Eg: 2
evaluate_expression(Expression, Expression) :-
    number(Expression).

%% And Operator (&&)
evaluate_expression(andop(Left, Right), Left_result and_then Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Or Operator (||)
evaluate_expression(orop(Left, Right), Left_result or_else Right_result) :-
    evaluate_expression(Left, Left_result),
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
evaluate_expression(post_increment(Assign_to, Increment_operation), Expression_result) :-
    evaluate_expression(Assign_to, Expression_result),
    evaluate_expression(Increment_operation, Increment_operation_result),
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Temp], Ptc_type),
    ptc_solver__sdl(Temp = Increment_operation_result),
    c_var__set_out_var(Assign_to, Temp).

%% Increment with ++ on the left side (Pre-increment)
%% Eg: ++x
evaluate_expression(pre_increment(Assign_to, Increment_operation), Expression_result) :-
    evaluate_expression(Increment_operation, Increment_operation_result),
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Expression_result], Ptc_type),
    ptc_solver__sdl(Expression_result = Increment_operation_result),
    c_var__set_out_var(Assign_to, Expression_result).

% %% Increment with -- on the right side (Post-decrement)
% %% Eg: x--
evaluate_expression(post_decrement(Assign_to, Decrement_operation), Expression_result) :-
    evaluate_expression(post_increment(Assign_to, Decrement_operation),Expression_result).

% %% Increment with -- on the left side (Pre-decrement)
% %% Eg: --x
evaluate_expression(pre_decrement(Assign_to, Decrement_operation), Expression_result) :-
    evaluate_expression(pre_increment(Assign_to, Decrement_operation), Expression_result).

%% Negation operator (Unary minus)
%% A value's sign being turned flipped with the minus operator
%% Eg: -x
evaluate_expression(-Expression, -Expression_result) :-
    evaluate_expression(Expression, Expression_result).

%% Assignment operator (=)
%% Eg: x = 2
evaluate_expression(assignment(Assign_to,Expression), Expression_result) :-
    evaluate_expression(Expression, Right_result),
    utils__assignment(Assign_to,Right_result, Expression_result).

evaluate_expression(function_call(Function_name, Arguments), Expression_result) :-
    function_handler(Function_name, Arguments, Expression_result). % Statement_handler.pl

%% Accessing an array element (Indexing)
%% Eg: Arr[2]
evaluate_expression(Array[Index], element(Var, [Expression_result])) :-
    c_array__get_out_var(Array, Var),
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index, Expression_result).