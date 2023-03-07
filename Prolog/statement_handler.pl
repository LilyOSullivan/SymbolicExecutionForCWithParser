:- ['declaration'].
:- ['label'].
:- ['test_case_generation'].

%% The entrypoint to function analysis
function_handler(Filename, Function_name, Body, Params, Return_type) :-
    parameter_handler(Params),
    statement_handler(Body, return(Return_value, Return_type)),
    once label_collectively(Params),
    c_var__get_out_var(Return_value, Return_value_normalised),
    cunit__write_test_case_all(Filename, Function_name, Params, Return_value_normalised, Return_type).
function_handler(_, _, _, _, _).

%% This variant of the function handler is used for function calls inside a function.
%% It is used to evaluate the return value of a function call
%% Parameters:
%%  Function_name: The name of the function to call
%%  Arguments: The arguments to pass to the function
%%  Return_value: The returned value from the function
function_handler(Function_info, Arguments, Return_value_normalised) :-
    utils__get_clean_function_info(Function_info, _, Params, Body, Return_type),
    once utils__assign_arguments_to_parameters(Arguments, Params),
    statement_handler(Body, return(Return_value, Return_type)),
    c_var__get_out_var(Return_value, Return_value_normalised).
%% Declare all parameters as variables
parameter_handler([]).
parameter_handler([void]) :- !.
parameter_handler([Declaration | More_declarations]) :-
    Declaration, % This calls declaration predicates in declaration.pl
    parameter_handler(More_declarations).

%% The primary loop dictating the execution of statements
%% It passes a final parameter of return_info
%%  Return_value is the value returned at a 'return' keyword, it is
%%               used to stop iterating in statement handler
%%  Return_type is the type of the return of the function
statement_handler([], _).
statement_handler([Statement | More_statements], return(Return_value, Return_type)) :-
    handle(Statement, return(Return_value, Return_type)),
    (
        free(Return_value) ->
            statement_handler(More_statements, return(Return_value, Return_type))
        ;
            true
    ).

%% This is if a new scope is created using { } not tied to a loop, if or function
%% Eg:
%%  int y = 15;
%%  {
%%      int x = 1;
%%  }
handle(List_of_statements, Return_info) :-
    statement_handler(List_of_statements, Return_info).

%% This occurs if a variable is declared in the function body
%% Eg:
%%  int x;
handle(declaration(Type, Vars), _) :-
    declaration(Type, Vars). % This calls declaration predicates in declaration.pl

%% If statement handler
handle(if_statement(_Line_Number, expression(Expression), If_body, Else_body), Return_info) :-
    (
        once evaluate_expression(Expression),
        statement_handler(If_body, Return_info)
    )
        ; % Deliberate Choice Point
    (
        once evaluate_expression(not(Expression)),
        statement_handler(Else_body, Return_info)
    ).

%% Empty return statement
%% Eg: return;
handle(return, void) :-
    writeln("Void Return").

%% Return statement with value to return
%% Eg: return 5;
handle(return(Expression), return(Return_value,Return_type)) :-
    utils__c_to_ptc_type(Return_type, Ptc_type),
    once evaluate_expression(Expression, Return_expression),
    ptc_solver__variable([Return_variable], Ptc_type),
    ptc_solver__sdl(Return_variable = Return_expression),
    c_var__create(Return_type, Ptc_type, Return_variable, "__return__", Return_value),
    writeln(Return_expression).

handle(init_record(Variable, function_call(Function_name, Arguments)), _) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    function_handler(Function_name, Arguments_result, Return_value),
    utils__assignment(Variable, Return_value, _).

handle(function_call(Function_name, Arguments), _) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    function_handler(Function_name, Arguments_result, _).

%% Handles assignment to a variable
%% This is commonly used as two steps, Declaration and Assignment of a variable.
%% int x = 5; // Declaration (int x;) and Assignment (x = 5;)
%% This becomes a declaration, handled above, and an assignment below
handle(assignment(Assign_to, Expression), _) :-
    evaluate_expression(Expression, Evaluated_expression),
    !,
    utils__assignment(Assign_to,Evaluated_expression, _).

%% Handle the += operator
%%  Breakdown: Variable += Expression
%%  Eg: x += 2;
handle(add_assignment(Variable, Expression), _) :-
    handle(assignment(Variable, Variable + Expression), _).

%% Handle the -= operator
%%  Breakdown: Variable -= Expression
%%  Eg: x -= 2;
handle(sub_assignment(Variable, Expression), _) :-
    handle(assignment(Variable, Variable - Expression), _).

%% Handle the *= operator
%%  Breakdown: Variable *= Expression
%%  Eg: x *= 2;
handle(mul_assignment(Variable, Expression), _) :-
    handle(assignment(Variable, Variable * Expression), _).

%% Handle the /= operator
%%  Breakdown: Variable /= Expression
%%  Eg: x /= 2;
handle(div_assignment(Variable, Expression), _) :-
    handle(assignment(Variable, Variable / Expression), _).

% Handle the %= operator
%  Breakdown: Variable %= Expression
%  Eg: x %= 2;
handle(mod_assignment(Variable, Expression), _) :-
    handle(assignment(Variable, mod(Variable, Expression)), _).

%% Handles the ++ post-increment-operator as a single line statement
%% Eg: x++;
handle(post_increment(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

%% Handles the ++ pre-increment-operator as a single line statement
%% Eg: ++x;
handle(pre_increment(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

%% Handles the -- post-decrement-operator as a single line statement
%% Eg: x--;
handle(post_decrement(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

%% Handles the -- pre-decrement-operator as a single line statement
%% Eg: --x;
handle(pre_decrement(Assign_to, Expression), _) :-
    handle(assignment(Assign_to, Expression), _).

% handle(_, _).

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
