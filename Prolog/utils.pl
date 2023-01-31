:- lib(ptc_solver).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

utils__evaluate_to_int(Expression, Integer_result) :-
    ptc_solver__variable([Integer_result], integer),
    ptc_solver__sdl(Integer_result = Expression).

%% Strip \n from the end of a string
%% The first parameter is the string with the newline (Eg: "Hello\n")
%% The second parameter is the string without the newline (Eg: "Hello")
utils__strip_right_newline(String_with_newline, String_stripped) :-
    (
        sub_string(String_with_newline, _, 1, 0, "\n") ->
            sub_string(String_with_newline, 0, _, 1, String_stripped)
        ;
            String_stripped = String_with_newline
    ).

% Question: Is there a better way to do this?
%           There likely exists a more-standard method for this task
%% Replace all spaces and colons with underscores
%% This is used to convert the date predicate results to a non-space string in main::setup_for_function
%% Certain characters are not allowed in the name of a directory, spaces and colon are examples of these characters
%% The first parameter is the string with spaces (Eg: "Hello :World")
%% The second parameter is the string with underscores (Eg: "Hello__World")
utils__replace_invalid_directory_chars_with_underscores([], []).
utils__replace_invalid_directory_chars_with_underscores(String_with_spaces,String_with_underscores) :-
    string_list(String_with_spaces,List_of_ascii_characters),

    ( foreach(Current_character, List_of_ascii_characters),
      foreach(New_character, List_of_ascii_characters_with_underscore)
      do
        SPACE_CHAR      = 32, % 32 is the ascii for a space character ( )
        COLON_CHAR      = 58, % 58 is the ascii for a colon character (:)
        UNDERSCORE_CHAR = 95, % 95 is the ascii for an underscore character (_)

        (Current_character = SPACE_CHAR ->
            New_character = UNDERSCORE_CHAR
        ;
        Current_character = COLON_CHAR ->
            New_character = UNDERSCORE_CHAR
        ;
            New_character = Current_character
        )
    ),
    string_codes(String_with_underscores,List_of_ascii_characters_with_underscore).

%% Removes the last character if it is a comma
utils__strip_right_comma(String_with_comma, String_without_comma) :-
    (
        sub_string(String_with_comma, _, 1, 0, ",") ->
            sub_string(String_with_comma, 0, _, 1, String_without_comma)
        ;
            String_without_comma = String_with_comma
    ).

% Below reduce-predicate is modified from
% https://stackoverflow.com/a/61809974
%% Applies a predicate to each element in a list,
%% and accumulates the return to a singular value.
%% This is used primarily to concatenate a list of strings together.
%% An implementation of reduce from the map-reduce pattern,
% or fold-right in some functional languages.
%% Parameters:
%% Predicate: The predicate to apply to each element in the list
%% List: The list to apply the predicate to
%% Default: The default value to return if the list is empty
%% Reduce_result: The result of the reduction
utils__reduce(_, [],  Default, Default).
utils__reduce(_, [Result], _, Result).
utils__reduce(Predicate, [First_element, Second_element|More_elements], _, Reduce_result):-
    call(Predicate, First_element, Second_element, Predicate_result),
    utils__reduce(Predicate, [Predicate_result|More_elements], _, Reduce_result),
    !.