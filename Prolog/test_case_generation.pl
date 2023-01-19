%IDEA: Keep a running counter for the number of tab-indentation's desired

:- use_module(c_array).
:- use_module(c_var).

:- dynamic get_and_set_test_folder_name/1.
:- dynamic set_test_cases/1.
:- dynamic set_test_id/1.

%% Generate test cases with failing backtrack
cunit_write_test_case_all(Filename, Function_name, Params, Return_value, Return_type) :-
    cunit_write_test_case(Filename, Function_name, Params, Return_value, Return_type),
    fail,
    !.

%IDEA: Test cases could be generated,
%      though this assumes determinism
%      Eg assert give_five() == 5
%% Generate test cases for a function with no parameters
%% A function with no parameters does not generate test cases.
cunit_write_test_case(_, Function_name, [void], _, _) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

%% Generate a singular test case
cunit_write_test_case(Filename, Function_name, Params, Return_value, Return_type) :-
    get_and_set_test_folder_name(Folder_name),
    concat_string(["./", Folder_name, "/"], Relative_path_to_test_directory),

    concat_string([Function_name, "_tests"], Test_suite_name),
    concat_string([Relative_path_to_test_directory, Test_suite_name, ".c"], Test_suite_filename),
    concat_string([Relative_path_to_test_directory, Test_suite_name, "_main.c"], Test_main_file),
    (
        cunit_is_first_test(Test_suite_filename) ->
            mkdir(Folder_name),
            open(Test_suite_filename, append, testcase),
            open(Test_suite_filename, read, testcase_read),
            cunit_write_test_include(Filename)
        ;
            % Put a new line to space out the test cases
            open(Test_suite_filename, append, testcase),
            open(Test_suite_filename, read, testcase_read),
            printf(testcase, "\n", [])
    ),
    open(Test_main_file, write, testcase_main),
    get_test_id(Test_id),
    term_string(Test_id, Test_id_as_string),
    New_test_id is Test_id + 1,
    set_test_id(New_test_id),
    concat_string(["test_", Test_id_as_string], Test_name),
    append_tests_cases(Test_name),
    create_declaration_section(Params, "", Declaration_section),
    cunit_create_assert(Function_name, Params, Return_value, Return_type, Assert),
    sprintf(Complete_test_case, "void %s(void) {\n\n %s \n %s}\n", [Test_name, Declaration_section, Assert]),
    printf(testcase, Complete_test_case, []),
    cunit_write_main(Test_suite_filename),
    close(testcase_main),
    close(testcase),
    close(testcase_read).

% IDEA: Split main function string among multiple strings
%% Create the main function for the test suite
cunit_write_main(Test_suite_filename) :-
    cunit_add_test_cases_to_suite(Add_tests_to_suite_string),
    printf(testcase_main, "#include \"%s\"\n\n", [Test_suite_filename]),
    printf(testcase_main, "int main()\n{\n   if (CUE_SUCCESS != CU_initialize_registry())\n      return CU_get_error();\n\n   CU_pSuite pSuite = CU_add_suite(\"Suite_1\", NULL, NULL);\n   if (NULL == pSuite) {\n      CU_cleanup_registry();\n      return CU_get_error();\n   }\n\n   %s\n   CU_basic_set_mode(CU_BRM_VERBOSE);\n   CU_basic_run_tests();\n   CU_cleanup_registry();\n   return CU_get_error();\n}\n", [Add_tests_to_suite_string]).

cunit_add_test_cases_to_suite(Out) :-
    get_test_cases(Tests),
    cunit_add_to_suite_loop(Tests, "", Out),
    set_test_cases(Tests).

cunit_add_to_suite_loop([], Accumulator, Accumulator).
cunit_add_to_suite_loop([Test_case|T], Accumulator, Out) :-
    % The sprint and concat_string are split to reduce the amount of chars on a single line of code; Readability
    sprintf(Result, "%s\tif (NULL == CU_add_test(pSuite, \"test case\", %s)) {\n\t\tCU_cleanup_registry();\n\t\treturn CU_get_error();\n\t}\n", [Accumulator, Test_case]),
    cunit_add_to_suite_loop(T, Result, Out).

cunit_create_assert(Function_name, Params, Return_value, Return_type, Out) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    get_var_names(Params, "", Var_names),
    sprintf(Out, "\tCU_ASSERT(%s(%s) == %s);\n", [Function_name, Var_names, Return_value_as_string]).

% FIXME: I imagine this is possible to be written without the use of an if
%% Checks if this is the first test case being generated.
%% This is to prevent the inclusion of the CUnit header files multiple times
%% in the same file due to backtracking
cunit_is_first_test(Filename) :-
    % The check for file size prevents read_string
    % from prompting for the amount of characters to read
    % if the file is empty/does not exist
    (
        exists(Filename), get_file_info(Filename, size, File_size), File_size > 0 ->
            open(Filename, read, testcase_read),
            read_string(testcase_read, _, First_chars),
            close(testcase_read),
            not string_contains(First_chars, "CUnit/Basic.h")
        ;
            true
    ).

%% The test include files. Called if it is the first test case
cunit_write_test_include(C_filename) :-
    printf(testcase, "#include \"CUnit/Basic.h\"\n", []),
    printf(testcase, "#include \"%s.c\"\n", [C_filename]).


% gtest_write_test_case_all(Function_name, [void], _) :-
%     write("No test cases to generate for "),
%     writeln(Function_name),
%     !.

% gtest_write_test_case_all(Function_name, Params, Return_value) :-
%     gtest_write_test_case(Function_name, Params, Return_value),
%     fail,
%     !.

% gtest_write_test_case(Function_name, [void], _) :-
%     write("No test cases to generate for "),
%     writeln(Function_name),
%     !.

% gtest_write_test_case(Function_name, Params, Return_value) :-
%     concat_string([Function_name, "_tests"], Test_suite_name),
%     concat_string([Test_suite_name, ".cpp"], Test_suite_filename),
%     open(Test_suite_filename, append, testcase),
%     open(Test_suite_filename, read, testcase_read),
%     (
%         gtest_is_first_test ->
%             gtest_write_test_include
%         ;
%             % Put a new line to space out the test cases
%             printf(testcase, "\n", [])
%     ),
%     printf(testcase, "TEST(%s, ", [Test_suite_name]),
%     get_test_id(Test_id),
%     term_string(Test_id, Test_id_as_string),
%     printf(testcase, Test_id_as_string, []),
%     printf(testcase, ") {\n", []),
%     New_test_id is Test_id + 1,
%     set_test_id(New_test_id),
%     gtest_write_assert_eq(Function_name, Params, Return_value),
%     printf(testcase, "}\n", []),
%     close(testcase),
%     close(testcase_read).

% gtest_write_assert_eq(Function_name, Params, Return_value) :-
%     printf(testcase, "\tASSERT_EQ(", []),
%     printf(testcase, Function_name, []),
%     printf(testcase, "(", []),
%     params_to_string(Params, "", Out),
%     printf(testcase, Out, []),
%     printf(testcase, "), ", []),
%     term_string(Return_value, Return_value_as_string),
%     printf(testcase, Return_value_as_string, []),
%     printf(testcase, ");\n", []).

% %% Check if the test includes are needed
% %% This is primarily for backtracking not to write includes multiple times
% gtest_is_first_test :-
%     read_string(testcase_read, 25, First_chars),
%     not string_contains(First_chars, "<gtest/gtest.h>").


% %% Write out any includes necessary for the test suite
% %% Necessary to ensure the gtest comes first
% %% Due to a check for the necessity of writing an include checking for gtest
% %% As a first line in the file
% gtest_write_test_include :-
%     printf(testcase, "#include <gtest/gtest.h>\n", []).
%     % printf(testcase, "#include "%s.c"\n", [C_filename]).


%% Check if a string contains a substring
string_contains(Original, Substring) :-
    sub_string(Original, _, _, _, Substring),
    !. % Stop on the first find. Interested exclusively if a substring exists

%% Gets the current test id
get_test_id(Out) :-
    retract(test_id(Out)),
    !.

%% Sets a new test id
set_test_id(New_id) :-
    asserta(test_id(New_id)).

%% Adds to the current list of all test cases. This is used in the generation
%% of the 'main' CUnit function
append_tests_cases(New_case) :-
    get_test_cases(All_tests),
    append(All_tests, [New_case], New_test_cases),
    set_test_cases(New_test_cases).

%% Updates the test cases in the internal database
set_test_cases(New_cases) :-
    asserta(tests(New_cases)).

%% Returns the test cases in the internal database
get_test_cases(New_cases) :-
    retract(tests(New_cases)),
    !.

get_and_set_test_folder_name(Folder_name) :-
    retract(test_folder_name(Folder_name)),
    !,
    asserta(test_folder_name(Folder_name)).

%% Removes the last character if it is a comma
strip_right_comma(In, Out) :-
    (
        sub_string(In, _, 1, 0, ",") ->
            sub_string(In, 0, _, 1, Out)
        ;
            Out = In
    ).

get_var_names([], Accumulator, Out) :-
    strip_right_comma(Accumulator, Out).
get_var_names([declaration(int, [H|_])|T], Accumulator, Out) :-
    c_var__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Accumulator, Var_name]),
    get_var_names(T, Result, Out).
get_var_names([declaration(intpointer, [H|_])|T], Accumulator, Out) :-
    c_array__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Accumulator, Var_name]),
    get_var_names(T, Result, Out).
get_var_names([declaration(charpointer, [H|_])|T], Accumulator, Out) :-
    c_array__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Accumulator, Var_name]),
    get_var_names(T, Result, Out).

% Below reduce-predicate is modified from
% https://stackoverflow.com/a/61809974
%% Applies a predicate to each element in a list,
%% and accumulates the return to a singular value.
%% This is used primarily to concatenate a list of strings together.
%% An implementation of reduce from the map-reduce pattern,
% or fold-left in some functional languages.
reduce(_, [],  Default, Default).
reduce(_, [A], _, A).
reduce(P3, [A, B|T], _, D):-
    call(P3, A, B, C),
    reduce(P3, [C|T], _, D),
    !.

create_declaration_section([], Accumulator, Accumulator).
create_declaration_section([declaration(int, [H|_])|T], Accumulator, Out) :-
    c_var__get_type(H, Type),
    create_single_declaration(Type, H, Declaration),
    sprintf(Result, "%s%s", [Accumulator, Declaration]),
    !,
    create_declaration_section(T, Result, Out).
create_declaration_section([declaration(intpointer, [H|_])|T], Accumulator, Out) :-
    c_array__get_type(H, {Type, _, _}),
    create_single_declaration(Type, H, Declaration),
    sprintf(Result, "%s%s", [Accumulator, Declaration]),
    !,
    create_declaration_section(T, Result, Out).
create_declaration_section([declaration(charpointer, [H|_])|T], Accumulator, Out) :-
    c_array__get_type(H, {Type, _, _}),
    create_single_declaration(Type, H, Declaration),
    sprintf(Result, "%s%s", [Accumulator, Declaration]),
    !,
    create_declaration_section(T, Result, Out).

create_single_declaration(int, Var, Out) :-
    c_var__get_all(Var, Var_Type, Ptc_in_var, Var_name),
    term_string(Ptc_in_var, Value),
    sprintf(Out, "\t%s %s = %s;\n", [Var_Type, Var_name, Value]).

create_single_declaration(intpointer, Var, Out) :-
    c_array__get_all(Var, {_, {Ptc_var, _}, Var_name, Size}),
    ptc_solver__get_array_index_elements(Ptc_var, Indexs),
    utils__get_all_array_inputs(Indexs, Values),
    ( foreach(Value, Values), foreach(X, Values_as_string) do
        term_string(Value, Value_as_string),
        concat_string([Value_as_string, ","], X)
    ),
    reduce(string_concat, Values_as_string, "", Result),
    strip_right_comma(Result, Result_stripped),
    sprintf(Array_values, "{%s}", [Result_stripped]),
    term_string(Size, Size_as_string),
    sprintf(Out, "\t%s %s[%s] = %s;\n", ["int", Var_name, Size_as_string, Array_values]).

create_single_declaration(charpointer, Var, Out) :-
    c_array__get_all(Var, {_, {Ptc_var, _}, Var_name, Size}),
    ptc_solver__get_array_index_elements(Ptc_var, Indexs),
    utils__get_all_array_inputs(Indexs, Values),
    ( foreach(Value, Values), foreach(X, Values_as_string) do
        % term_string(Value, Value_as_string),
        string_codes(Value_as_string, [Value]),
        concat_string(["'", Value_as_string, "',"], X)
    ),
    reduce(string_concat, Values_as_string, "", Result),
    strip_right_comma(Result, Result_stripped),
    sprintf(Array_values, "{%s}", [Result_stripped]),
    term_string(Size, Size_as_string),
    sprintf(Out, "\t%s %s[%s] = %s;\n", ["char", Var_name, Size_as_string, Array_values]).

create_return(Return_value, int, Out) :-
    term_string(Return_value, Out).
create_return(Return_value, char, Out) :-
    string_codes(Value_as_string, [Return_value]),
    concat_string(["'", Value_as_string, "'"], Out).