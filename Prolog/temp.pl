:- dynamic function_definition/4.
:- dynamic global_variables/2.

read_prolog_file(Relative_path) :-
    read_terms_from_file(Relative_path, Result),
    asserta(Result).

process_global_variables :-
    parsed(Terms),
    initialise_globals(Terms).

initialise_globals([]).
initialise_globals([H|T]) :-
    (H = global_variables(Statements, _) ->
        statement_handler(Statements, _) % From Statement_handler.pl
    ;
        true
    ),
    initialise_globals(T).

find_function_information(Function_name, Params, Body, Return_type) :-
    parsed(Terms),
    find_function(Terms, Function_name, Params, Body, Return_type),
    !.

find_function([],_,_,_,_).
find_function([Term|More_terms], Function_name, Params, Body, Return_type) :-
    (Term = function_definition(Function_name, Params, Body, Return_type) ->
        true
    ;
        find_function(More_terms, Function_name, Params, Body, Return_type)
    ).

temp :-
    read_terms_from_file("sign.pl", Result),
    compile_list_of_terms(Result),
    retract(function_definition(Function_name, _, _, _)),
    printf("Function name: %s\n", [Function_name]).

read_terms_from_file(Filename, Result) :-
    open(Filename, read, Stream),
    read_terms_from_stream(Stream, Result),
    close(Stream).

read_terms_from_stream(Stream, Term) :-
    read_term(Stream, Term, []).