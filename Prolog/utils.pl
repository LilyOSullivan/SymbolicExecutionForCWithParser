:- lib(ptc_solver).

% From Eileen's Code
utils__get_all_array_inputs([], []).
utils__get_all_array_inputs([(_, Value)|Rest], [Value|Rest2]) :-
	utils__get_all_array_inputs(Rest, Rest2).

utils__evaluate_to_int(Expression, Integer_result) :-
    ptc_solver__variable([Integer_result], integer),
    ptc_solver__sdl(Integer_result = Expression),
    ptc_solver__label_integers([Integer_result]),
    !.

% %% Strip \n from the end of a string
% %% The first parameter is the string with the newline (Eg: "Hello\n")
% %% The second parameter is the string without the newline (Eg: "Hello")
% utils__strip_right_newline(String_with_newline, String_stripped) :-
%     (
%         sub_string(String_with_newline, _, 1, 0, "\n") ->
%             sub_string(String_with_newline, 0, _, 1, String_stripped)
%         ;
%             String_stripped = String_with_newline
%     ).

% TODO: This likely should do more than printing
%% Detects if a C-code error is occurring: Not all code paths return a value
utils__detect_not_all_code_paths_return(Return_value,Return_type) :-
    (Return_type \== void, var(Return_value) ->
        (
            writeln("ERROR: Not all code paths return a value!!"),
            Return_value = 0
        )
    ;
        (
            true % All okay, no error
        )
    ).

% QUESTION: Is there a better way to do this?
%           There likely exists a more-standard method for this task
%% Replace all spaces and colons with underscores
%% This is used to convert the date predicate result to a string in main::setup_for_function
%% Certain characters are not allowed in the name of a directory, spaces and colon are examples of these characters
%% The first parameter is the string with spaces (Eg: "He:llo World")
%% The second parameter is the string with underscores (Eg: "He_llo_World")
% utils__replace_invalid_directory_chars_with_underscores([], []).
% utils__replace_invalid_directory_chars_with_underscores(String_with_spaces,String_with_underscores) :-
%     string_list(String_with_spaces,List_of_ascii_characters),

%     ( foreach(Current_character, List_of_ascii_characters),
%       foreach(New_character, List_of_ascii_characters_with_underscore)
%       do
%         SPACE_CHAR      = 32, % 32 is the ascii for a space character ( )
%         COLON_CHAR      = 58, % 58 is the ascii for a colon character (:)
%         UNDERSCORE_CHAR = 95, % 95 is the ascii for an underscore character (_)

%         (Current_character = SPACE_CHAR ->
%             New_character = UNDERSCORE_CHAR
%         ;
%         Current_character = COLON_CHAR ->
%             New_character = UNDERSCORE_CHAR
%         ;
%             New_character = Current_character
%         )
%     ),
%     string_codes(String_with_underscores,List_of_ascii_characters_with_underscore).

%% Removes the last character if it is a comma
utils__strip_right_comma(String_with_comma, String_without_comma) :-
    (
        sub_string(String_with_comma, _, 1, 0, ",") ->
            sub_string(String_with_comma, 0, _, 1, String_without_comma)
        ;
            String_without_comma = String_with_comma
    ).

% Join a list of strings together
% Eg: join(["a","b","c"],Result) -> Result = "abc"
utils__join([], "").
utils__join([String|More_strings], Result) :-
    utils__join(More_strings, Strings_join_so_far),
    concat_string([String, Strings_join_so_far], Result).

utils__assignment(Assign_to,Value,Assigned_value) :-
    c_var__get_ptc_type(Assign_to, Ptc_type),
    ptc_solver__variable([Assigned_value], Ptc_type),
    ptc_solver__sdl(Assigned_value, Value),
    c_var__set_out_var(Assign_to, Assigned_value).