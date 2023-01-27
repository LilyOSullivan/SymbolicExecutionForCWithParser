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
%% Replace all spaces with underscores
%% This is used to convert the date predicate results to a non-space string in main::setup_for_function
%% The first parameter is the string with spaces (Eg: "Hello World")
%% The second parameter is the string with underscores (Eg: "Hello_World")
utils__replace_spaces_with_underscores([], []).
utils__replace_spaces_with_underscores(String_with_spaces,String_with_underscores) :-
    string_list(String_with_spaces,List_of_ascii_characters),
    (foreach(Current_character, List_of_ascii_characters), foreach(New_character, List_of_ascii_characters_with_underscore) do
        Current_character = 32 -> % 32 is the ascii for a space character ( )
            New_character = 95 % 95 is the ascii for an underscore character (_)
        ;
            New_character = Current_character
    ),
    string_codes(String_with_underscores,List_of_ascii_characters_with_underscore).
