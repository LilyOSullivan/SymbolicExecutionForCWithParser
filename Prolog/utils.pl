:- lib(ptc_solver).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

utils__evaluate_to_int(Expression, Out) :-
    ptc_solver__variable([Out], integer),
    ptc_solver__sdl(Out = Expression).

utils__ptc_type(int, integer).

% Strip \n from the end of a string
utils__strip_right_newline(In, Out) :-
    (
        sub_string(In, _, 1, 0, "\n") ->
            sub_string(In, 0, _, 1, Out)
        ;
            Out = In
    ).



% utils__right_strip_newline(String, String_without_newline) :-
%     string_list(String, List_of_ascii_characters),
%     (foreach(Character, List_of_ascii_characters), foreach(New_character, List_of_ascii_characters_without_newline) do
%         Character = 10 -> % 10 is the ascii code for \n
%             true % do nothing
%         ;
%             New_character = Character
%     ),
%     string_codes(String_without_newline,List_of_ascii_characters_without_newline).

utils__replace_spaces_with_underscores([], []).
utils__replace_spaces_with_underscores(String_with_spaces,String_with_underscores) :-
    string_list(String_with_spaces,List_of_ascii_characters),
    (foreach(Character, List_of_ascii_characters), foreach(New_character, List_of_ascii_characters_with_underscore) do
        Character = 32 ->
            New_character = 95
        ;
            New_character = Character
    ),
    string_codes(String_with_underscores,List_of_ascii_characters_with_underscore).
