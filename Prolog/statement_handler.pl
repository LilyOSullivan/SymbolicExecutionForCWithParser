:- ['test_case_generation'].
:- ['expressions'].
:- ['concretise'].
:- ['declaration'].

function_handler(Function_Name,Body,Params,Return_Type) :-
    parameter_handler(Params),
    statement_handler(Body,[_,Return_Value,Return_Type]),
    concretise(Params),
    % gtest_write_test_case_all(Function_Name,Params,Return_Value).
    cunit_write_test_case_all(Function_Name,Params,Return_Value).

% Without cut below it is matching [H|T] with H being void
parameter_handler([void]):- !.
parameter_handler([]).
parameter_handler([H|T]) :-
    H, % This calls declaration predicates in declaration.pl
    parameter_handler(T).

% IDEA: What if instead of Return_flag, it is checked if Return_value is instantiated?
% QUESTION: What if a function returns nothing (void return)?
%% The primary loop dictating the execution of statements
%% It passes a final parameter of return flag information, in three parts
%% The information is a list of: [Return_flag,Return_value,Return_type]
%%  Return_flag is true of a return statement has been encountered. This is used to stop the statement handler loop
%%  Return_value is the value returned at a return function, used in test generation
%%  Return_type is the function return type, used to ensure the correct type is returned
statement_handler([],_).
statement_handler([H|T],[Return_flag|Rest]) :-
    handle(H,[Return_flag|Rest]),
    (
        Return_flag == true ->
            true
        ;
            statement_handler(T,[Return_flag|Rest])
    ).

handle(List_Of_Statements,Return_flags) :-
    statement_handler(List_Of_Statements,Return_flags).

%% This occurs if a variable is declared in the function body and are not arguments
handle(declaration(Type,Vars),_) :-
    declaration(Type,Vars).

handle(if_statement(_Line_Number,expression(Constraint),If_body,Else_body),Return_flags) :-
    evaluate_expression(Constraint),
    (
        statement_handler(If_body,Return_flags)
    )
        ; % Deliberate Choice Point
    (
        evaluate_expression(not(Constraint)),
        statement_handler(Else_body,Return_flags)
    ).

handle(return(Expression),[Return_flag,Return_value,Return_type]) :-
    Return_flag = true,
    evaluate_expression(Expression,Expression_Result),
    concretise(Expression_Result,Return_type,Out),
    Return_value = Out,
    writeln(Out).

handle(assignment(X,Value),_) :-
    evaluate_expression(Value,Out),
    ptc_solver__sdl(X=Out).
    % QUESTION: Is eq_cast needed above if X is an int?
    %           Eg: (Assuming is_integer returns true for integer variables)
    %               is_integer(X) ->
    %                   ptc_solver__sdl(eq_cast(X, Value)).

% handle(assignment(int(Z),extern(f(X),Library_Name)),_) :-
%     ptc_solver__variable([X],integer),
%     ptc_solver__variable([Z],integer),
%     handle(extern(f(X),Library_Name),Z),
%     !.

% handle(extern(f(X),Library_Name),Out,Return_flags) :-
%     (
%         var(X) ->
%             suspend(
%                 handle(extern(f(X),Library_Name),Out,Return_flags),
%                 1,
%                 X->inst
%             )
%         ;
%             load(Library_Name),
%             external(external_call/2,p_external_call),
%             external_call(Result,X),
%             writeln(Result),
%             ptc_solver__sdl(eq_cast(Out, Result))
%     ).
