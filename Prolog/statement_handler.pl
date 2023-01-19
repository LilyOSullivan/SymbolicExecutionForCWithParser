:- ['label'].

:- ['test_case_generation'].
:- ['declaration'].
:- use_module(expressions).

%% The entrypoint to function analysis
function_handler(Filename, Function_Name, Body, Params, Return_type) :-
    parameter_handler(Params),
    statement_handler(Body, return(_, Return_Value, Return_type)),
    label(Params),
    % gtest_write_test_case_all(Filename, Function_Name, Params, Return_Value).
    cunit_write_test_case_all(Filename, Function_Name, Params, Return_Value, Return_type).
% function_handler(_, _, _, _, _).

parameter_handler([]).
parameter_handler([Declaration|More_declarations]) :-
    Declaration \= void,
    Declaration, % This calls declaration predicates in declaration.pl
    parameter_handler(More_declarations).

% IDEA: What if instead of Return_flag, it is checked if Return_value is instantiated?
% QUESTION: What if a function returns nothing (void return)?
%% The primary loop dictating the execution of statements
%% It passes a final parameter of return flag information, in three parts
%% The information is a list of: [Return_flag, Return_value, Return_type]
%%  Return_flag is true of a return statement has been encountered. This is used to stop the statement handler loop
%%  Return_value is the value returned at a return function, used in test generation
%%  Return_type is the function return type, used to ensure the correct type is returned
statement_handler([], _).
statement_handler([Statement|More_statements], return(Return_flag,Return_value,Return_type)) :-
    handle(Statement, return(Return_flag,Return_value,Return_type)),
    (
        Return_flag == true ->
            true
        ;
            statement_handler(More_statements, return(Return_flag,Return_value,Return_type))
    ).

%% This if a new scope is created using { } not tied to a loop, if or function
%% Eg:
%%  int y = 15;
%%  {
%%      int x = 1;
%%  }
handle(List_Of_Statements, Return_flags) :-
    statement_handler(List_Of_Statements, Return_flags).

%% This occurs if a variable is declared in the function body
%% Eg:
%%  int x;
handle(declaration(Type, Vars), _) :-
    declaration(Type, Vars). % This calls declaration predicates in declaration.pl

%% If statement handler
handle(if_statement(_Line_Number, expression(Constraint), If_body, Else_body), Return_flags) :-
    % evaluate_expression(Constraint),
    (
        evaluate_expression(Constraint),
        statement_handler(If_body, Return_flags)
    )
        ; % Deliberate Choice Point
    (
        evaluate_expression(not(Constraint)),
        statement_handler(Else_body, Return_flags)
    ).

%% Return statement that returns a value
handle(return(Expression), return(true, Out, Return_type)) :-
    evaluate_expression(Expression, Expression_Result),
    !,
    label(Expression_Result, Return_type, Out),
    writeln(Out).

%% Empty return statement
handle(return, return(true, void, _)) :-
    writeln("Void Return").

%% Handles assignment to a variable
%% This is commonly used as two steps, Declaration and Assignment, of a variable.
%% int x = 5;
%% Becomes a declaration, handled above, and an assignment below
handle(assignment(Variable, Expression), _) :-
    evaluate_expression(Expression, Evaluated_expression),
    !,
    c_var__get_ptc_type(Variable, Ptc_type),
    ptc_solver__variable([Temp], Ptc_type),
    ptc_solver__sdl(eq_cast(Temp, Evaluated_expression)),
    c_var__set_out_var(Variable, Temp).

%% Handle the += operator
%%  Breakdown: Variable += Expression
%%  Eg: x += 2;
handle(add_assignment(Variable, Expression), _) :-
    Expression_with_add = (Variable + Expression),
    handle(assignment(Variable, Expression_with_add), _).

%% Handle the -= operator
%%  Breakdown: Variable -= Expression
%%  Eg: x -= 2;
handle(sub_assignment(Variable, Expression), _) :-
    Expression_with_subtraction = (Variable - Expression),
    handle(assignment(Variable, Expression_with_subtraction), _).

%% Handle the *= operator
%%  Breakdown: Variable *= Expression
%%  Eg: x *= 2;
handle(mul_assignment(Variable, Expression), _) :-
    Expression_with_multiplication = (Variable * Expression),
    handle(assignment(Variable, Expression_with_multiplication), _).

%% Handle the /= operator
%%  Breakdown: Variable /= Expression
%%  Eg: x /= 2;
handle(div_assignment(Variable, Expression), _) :-
    Expression_with_divide = (Variable / Expression),
    handle(assignment(Variable, Expression_with_divide), _).

% Handle the %= operator
%  Breakdown: Variable %= Expression
%  Eg: x %= 2;
handle(mod_assignment(Variable, Expression), _) :-
    Expression_with_mod = mod(Variable,Expression),
    handle(assignment(Variable, Expression_with_mod), _).

%% Handles the ++ post-increment-operator as a single line statement
%% Eg: x++;
handle(post_increment(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

%% Handles the ++ pre-increment-operator as a single line statement
%% Eg: ++x;
handle(pre_increment(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

handle(post_decrement(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

handle(pre_decrement(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

% handle(assignment(int(Z), extern(f(X), Library_hName)), _) :-
%     ptc_solver__variable([X], integer),
%     ptc_solver__variable([Z], integer),
%     handle(extern(f(X), Library_Name), Z),
%     !.

% handle(extern(f(X), Library_Name), Out, Return_flags) :-
%     (
%         var(X) ->
%             suspend(
%                 handle(extern(f(X), Library_Name), Out, Return_flags),
%                 1,
%                 X->inst
%             )
%         ;
%             load(Library_Name),
%             external(external_call/2, p_external_call),
%             external_call(Result, X),
%             writeln(Result),
%             ptc_solver__sdl(eq_cast(Out, Result))
%     ).
