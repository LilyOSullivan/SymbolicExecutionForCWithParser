
:- ['label'].
:- ['test_case_generation'].

:- lib(ic).

%% The entrypoint to function analysis
symbolically_execute_function(Filename, Function_name, Body, Params, Function_return_type) :-
    parameter_handler(Params),
    statement_handler(Body, return(Return_value, Function_return_type)),
    label_collectively(Params),
    c_var__get_out_var(Return_value, Return_value_normalised),
    write_test_case_all(Filename, Function_name, Params, Return_value_normalised, Function_return_type).
symbolically_execute_function(_, _, _, _, _).

%% This variant of the function handler is used for function calls inside a function.
%% It is used to evaluate the return value of a function call
%% Parameters:
%%  Function_name: The name of the function to call
%%  Arguments: The arguments to pass to the function
%%  Return_value: The returned value from the function
symbolically_execute_function(Function_info, Arguments, Return_value_normalised) :-
    function_info__get_body(Function_info, Body),
    declare_static_variables(Body),

    function_info__get_clean_function(Function_info, _, Params, Clean_body, Return_type),
    utils__assign_arguments_to_parameters(Arguments, Params),
    statement_handler(Clean_body, return(Return_value, Return_type)),
    c_var__get_out_var(Return_value, Return_value_normalised).

%% Declare all parameters as variables
parameter_handler([]).
parameter_handler([void]) :- !.
parameter_handler([Declaration | More_declarations]) :-
    Declaration, % This calls declaration predicates in declaration.pl
    parameter_handler(More_declarations).

%% The primary loop dictating the execution of statements
%% Also handles if a new scope is created using { } not tied to a loop, if or function
%% Eg:
%%  int y = 15;
%%  {
%%      int x = 1;
%%  }
%% It passes a final parameter of return_info
%%  Return_value is the value returned at a 'return' keyword, it is
%%               used to stop iterating in statement handler
%%  Return_type is the type of the return of the function
statement_handler([], _).
statement_handler([Statement | More_statements], return(Return_value, Return_type)) :-
    statement_handler(Statement, return(Return_value, Return_type)),
    (
        free(Return_value) ->
            statement_handler(More_statements, return(Return_value, Return_type))
        ;
            true
    ).

%% This occurs if a variable is declared in the function body
%% Eg:
%%  int x;
statement_handler(declaration(Type, Vars, Assignment), _) :-
    (
        is_static_declared(declaration(Type, Vars, Assignment)) ->
            % This is already declared at function call-time
            true
    ;
        declaration(Type, Vars, Assignment) % This calls declaration predicates in declaration.pl
    ).

%% If statement handler
statement_handler(if_statement(_Line_Number, expression(Expression), If_body, Else_body), Return_info) :-
    (
        evaluate_expression(Expression),
        statement_handler(If_body, Return_info)
    )
        ; % Deliberate Choice Point
    (
        evaluate_expression(not(Expression)),
        statement_handler(Else_body, Return_info)
    ).

%% Empty return statement
%% Eg: return;
statement_handler(return, return(Return_value, Return_type)) :-
    c_var__create(Return_type, void, local, "__return__", _, Return_value),
    writeln("Void Return").

%% Return statement with value to return
%% Eg: return 5;
statement_handler(return(Expression), return(Return_value, Return_type)) :-
    evaluate_expression(Expression, Return_expression),
    utils__demotion(Return_expression, Return_type, Demoted_return),
    ptc_solver__variable([Return_variable], Return_type),
    ptc_solver__sdl(eq_cast(Return_variable, Demoted_return)),
    c_var__create(Return_type, Return_variable, local, "__return__", _, Return_value),
    writeln(Return_variable),
    !.

%% Function call that is assigned to a variable
%% Eg:
%%  int x = give_five();
statement_handler(init_record(Variable, function_call(Function_name, Arguments)), _) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    symbolically_execute_function(Function_name, Arguments_result, Return_value),
    utils__assignment(Variable, Return_value, _).

%% Function call on it's own, without assigning the return value
%% Eg:
%%  give_five();
statement_handler(function_call(Function_name, Arguments), _) :-
    maplist(evaluate_expression, Arguments, Arguments_result),
    symbolically_execute_function(Function_name, Arguments_result, _).

%% Handles assignment to a variable
%% This is commonly used as two steps, Declaration and Assignment of a variable.
%% int x = 5; // Declaration (int x;) and Assignment (x = 5;)
%% This becomes a declaration, handled above, and an assignment below
statement_handler(assignment(Assign_to, Expression), _) :-
    evaluate_expression(assignment(Assign_to, Expression), _).

%% This is incase of unnecessary semicolons
%% Eg:
%%  int x = 5;;;
%%  ;;
statement_handler(null, _).

%% This is incase of an expression existing as a statement
%% Eg:
%%  2/2;
%%  2+give_five();
%%  2;
%%  2+(x=3);
statement_handler(expression_statement(Expression), _) :-
    evaluate_expression(Expression, _).


statement_handler(record_declaration_type(_Type, Type_name, Fields), _) :-
    ptc_solver__type(Type_name, record, Fields).

statement_handler(record_declaration_nofields(_ , Type_name, [LC_p1_6]), _) :-
    declaration(Type_name, [LC_p1_6], []).

% statement_handler(assignment(int(Z), extern(f(X), Library_hName)), _) :-
%     ptc_solver__variable([X], integer),
%     ptc_solver__variable([Z], integer),
%     statement_handler(extern(f(X), Library_Name), Z),
%     !.

% statement_handler(extern(f(X), Library_Name), Out, Return_flags) :-
%     (
%         var(X) ->
%             suspend(
%                 statement_handler(extern(f(X), Library_Name), Out, Return_flags),
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
