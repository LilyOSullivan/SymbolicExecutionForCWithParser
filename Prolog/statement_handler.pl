:- ['label'].
:- ['test_case_generation'].
:- ['declaration'].

%% The entrypoint to function analysis
function_handler(Filename, Function_Name, Body, Params, Return_type) :-
    parameter_handler(Params),
    !,
    statement_handler(Body, Return_value),
    utils__detect_not_all_code_paths_return(Return_value, Return_type),
    label_collectively(Params),
    utils__normalise_return(Return_value,Return_type,Normalised_return_value),
    cunit__write_test_case_all(Filename, Function_Name, Params, Normalised_return_value, Return_type).
function_handler(_, _, _, _, _).


%% Declare all parameters as variables
parameter_handler([]).
parameter_handler([void]) :- !.
parameter_handler([Declaration|More_declarations]) :-
    Declaration, % This calls declaration predicates in declaration.pl
    parameter_handler(More_declarations).

%% The primary loop dictating the execution of statements
%% It passes a final parameter of return_value
%%  Return_value is the value returned at a 'return' keyword, it is
%%               used to stop iterating in statement handler
statement_handler([], _).
statement_handler([Statement|More_statements], Return_value) :-
    handle(Statement, Return_value),
    (
        var(Return_value) ->
            statement_handler(More_statements, Return_value)
        ;
            true
    ).

%% This is if a new scope is created using { } not tied to a loop, if or function
%% Eg:
%%  int y = 15;
%%  {
%%      int x = 1;
%%  }
handle(List_of_statements, Return_value) :-
    statement_handler(List_of_statements, Return_value).

%% This occurs if a variable is declared in the function body
%% Eg:
%%  int x;
handle(declaration(Type, Vars), _) :-
    declaration(Type, Vars). % This calls declaration predicates in declaration.pl

%% If statement handler
handle(if_statement(_Line_Number, expression(Expression), If_body, Else_body), Return_value) :-
    (
        evaluate_expression(Expression),
        statement_handler(If_body, Return_value)
    )
        ; % Deliberate Choice Point
    (
        evaluate_expression(not(Expression)),
        statement_handler(Else_body, Return_value)
    ).

%% Return statement with value to return
handle(return(Expression), Return_value) :-
    evaluate_expression(Expression, Return_value),
    !,
    writeln(Return_value).

%% Empty return statement
handle(return, void) :-
    writeln("Void Return").

%% Handles assignment to a variable
%% This is commonly used as two steps, Declaration and Assignment, of a variable.
%% int x = 5;
%% This becomes a declaration, handled above, and an assignment below
handle(assignment(Assign_to, Expression), _) :-
    evaluate_expression(Expression, Evaluated_expression),
    !,
    utils__assignment(Assign_to,Evaluated_expression,_).

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
