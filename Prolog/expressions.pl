:- lib(ptc_solver).

:- use_module(c_array).
:- use_module(c_var).

%% Evaluate an expression. Failing if it is invalid, passing if it is valid.
%% Evaluate a not expression (!). Failing if it is invalid, passing if it is valid.
evaluate_expression(not(Expression)) :-
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(not (Expression_result = 1)),
    !.

evaluate_expression(Expression) :-
    evaluate_expression(Expression, Expression_result),
    ptc_solver__sdl(Expression_result = 1),
    !.

%% Returns the 'out' ptc_variable of a c_var
evaluate_expression(Expression, Ptc_variable) :-
    var(Expression),
    c_var__get_out_var(Expression, Ptc_variable),
    !.

%% Returns a number-constant
%% Eg: 2
evaluate_expression(Expression, Expression) :-
    number(Expression),
    !.

%% And Operator (&&)
evaluate_expression(andop(Left, Right), Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = 1 and_then Right_result = 1, Expression_result)).

%% Or Operator (||)
evaluate_expression(orop(Left, Right), Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = 1 or_else Right_result = 1, Expression_result)).

%% Not Operator (!)
evaluate_expression(exclamation(Expression), Expression_result) :-
    evaluate_expression(Expression, Result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Result = 0, Expression_result)).

%% Modulo Operator (%)
evaluate_expression(mod(Left ,Right), Left_result mod Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Not Equal (!=)
evaluate_expression(Left<>Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result <> Right_result, Expression_result)).

% %% Equal Boolean Operator (==)
% evaluate_expression(Left==Right, Left_result=Right_result) :-
%     evaluate_expression(Left, Left_result),
%     evaluate_expression(Right, Right_result).

%% Equal Boolean Operator (==)
evaluate_expression(Left==Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result = Right_result, Expression_result)).

%% Greater than Boolean Operator (>)
% evaluate_expression(Left>Right, Left_result>Right_result) :-
%     evaluate_expression(Left, Left_result),
%     evaluate_expression(Right, Right_result).

%% Greater than Boolean Operator (>)
evaluate_expression(Left>Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result > Right_result, Expression_result)).

%% Greater than or equal Boolean Operator (>=)
% evaluate_expression(Left>=Right, Left_result>=Right_result) :-
%     evaluate_expression(Left, Left_result),
%     evaluate_expression(Right, Right_result).

evaluate_expression(Left>=Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result >= Right_result, Expression_result)).

%% Less than Boolean Operator (<)
% evaluate_expression(Left<Right, Left_result<Right_result) :-
%     evaluate_expression(Left, Left_result),
%     evaluate_expression(Right, Right_result).

evaluate_expression(Left<Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result < Right_result, Expression_result)).

%% Less than or equal Boolean Operator (<=)
% evaluate_expression(Left<=Right, Left_result<=Right_result) :-
%     evaluate_expression(Left, Left_result),
%     evaluate_expression(Right, Right_result).

evaluate_expression(Left<=Right, Expression_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result),
    ptc_solver__variable([Expression_result], boolean_int),
    ptc_solver__sdl(reif(Left_result <= Right_result, Expression_result)).

%% Subtraction (Minus) Operator for two expressions (-)
evaluate_expression(Left-Right, Left_result-Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Addition Operator (+)
evaluate_expression(Left+Right, Left_result+Right_result) :-
    evaluate_expression(Left, Left_result),
    evaluate_expression(Right, Right_result).

%% Multiplication Operator for two expressions (*)
evaluate_expression(multiply(Left, Right), Left_result*Right_result) :-
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
%% A value's sign being flipped with the minus operator
%% Eg: -x
evaluate_expression(-Expression, -Expression_result) :-
    evaluate_expression(Expression, Expression_result).

%% Assignment operator (=)
%% Eg: x = 2
evaluate_expression(assignment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(Expression, Right_result),
    utils__assignment(Assign_to,Right_result, Expression_result).

%% Handle the += operator
%%  Breakdown: Variable += Expression
%%  Eg: x += 2;
evaluate_expression(add_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable + Expression), Expression_result).

%% Handle the -= operator
%%  Breakdown: Variable -= Expression
%%  Eg: x -= 2;
evaluate_expression(sub_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable - Expression), Expression_result).

%% Handle the *= operator
%%  Breakdown: Variable *= Expression
%%  Eg: x *= 2;
evaluate_expression(mul_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, multiply(Variable, Expression)), Expression_result).

%% Handle the /= operator
%%  Breakdown: Variable /= Expression
%%  Eg: x /= 2;
evaluate_expression(div_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, Variable / Expression), Expression_result).

% Handle the %= operator
%  Breakdown: Variable %= Expression
%  Eg: x %= 2;
evaluate_expression(mod_assignment(Variable, Expression), Expression_result) :-
    evaluate_expression(assignment(Variable, mod(Variable, Expression)), Expression_result).

%% Handles the ++ post-increment-operator as a single line statement
%% Eg: x++;
evaluate_expression(post_increment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the ++ pre-increment-operator as a single line statement
%% Eg: ++x;
evaluate_expression(pre_increment(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the -- post-decrement-operator as a single line statement
%% Eg: x--;
evaluate_expression(post_decrement(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Handles the -- pre-decrement-operator as a single line statement
%% Eg: --x;
evaluate_expression(pre_decrement(Assign_to, Expression), Expression_result) :-
    evaluate_expression(assignment(Assign_to, Expression), Expression_result).

%% Function call as expression
%% Eg: int x = 2+give_five();
evaluate_expression(function_call(Function_info, Arguments), Expression_result) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    function_handler(Function_info, Arguments_result, Expression_result). % Statement_handler.pl

%% Accessing an array element (Indexing)
%% Eg: Arr[2]
evaluate_expression(Array[Index], element(Var, [Expression_result])) :-
    c_array__get_out_var(Array, Var),
    % The index could be an expression (Eg: Arr[2+2])
    evaluate_expression(Index, Expression_result).