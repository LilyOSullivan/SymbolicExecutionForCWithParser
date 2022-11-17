:- ['utilities'].
:- ['expression'].
:- ['concretise'].
:- ['declaration'].

function_handler(Body,Params,Return_Type) :-
    parameter_handler(Params),
    statement_handler(Body,[_,Return_Type]),
    concretise(Params). % QUESTION Label on return statement

parameter_handler([]).
parameter_handler([H|T]) :-
    H,
    parameter_handler(T).

statement_handler([],_).
statement_handler([H|T],[Return_flag|Rest]) :-
    handle(H,[Return_flag|Rest]),
    (
        Return_flag == true ->
            true
        ;
            statement_handler(T,[Return_flag|Rest])
    ).

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

handle(return(Expression),[Return_flag,_Return_Type|_]) :-
    Return_flag = true,
    % evaluate_expression(Expression,Expression_Result),
    % concretise(Expression_Result,Return_Type,Out),
    % writeln(Out).
    writeln(Expression).


% handle(assignment(int(Z),extern(f(X),Library_Name)),_) :-
%     ptc_solver__variable([X],integer),
%     ptc_solver__variable([Z],integer),
%     handle(extern(f(X),Library_Name),Z),
%     !.

% handle(assignment(int(X),Value),_) :-
%     handle(int(X)),
%     ptc_solver__sdl(eq_cast(X, Value)).

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

