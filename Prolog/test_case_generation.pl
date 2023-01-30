%IDEA: Keep a running counter for the number of tab-indentation's desired

:- use_module(c_array).
:- use_module(c_var).


%% Generate test cases with failing backtrack
cunit__write_test_case_all(Filename, Function_name, Params, Return_value, Return_type) :-
    cunit__write_test_case(Filename, Function_name, Params, Return_value, Return_type),
    fail,
    !.

%IDEA: Test cases could be generated,
%      though this assumes determinism
%      Eg assert give_five() == 5
%% Generate test cases for a function with no parameters
%% A function with no parameters does not generate test cases, for now.
cunit__write_test_case(_, Function_name, [void], _, _) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

%% Generate a singular test case
cunit__write_test_case(Filename, Function_name, Params, Return_value, Return_type) :-
    get_test_folder_path(Path_to_test_directory),
    concat_string([Function_name, "_tests"], Test_suite_name),
    concat_string([Path_to_test_directory, Test_suite_name, ".c"], Test_suite_filepath),
    (
        cunit__is_first_test(Test_suite_filepath) ->
            mkdir(Path_to_test_directory),
            open(Test_suite_filepath, append, testcase),
            cunit__write_test_include(Filename)
        ;
            open(Test_suite_filepath, append, testcase),
            % Put a new line to visually space out the test cases
            printf(testcase, "\n", [])
    ),
    create_declaration_section(Params, "", Declaration_section),
    cunit__create_assert(Function_name, Params, Return_value, Return_type, CUnit_assert),
    get_test_name(Test_name),
    printf(testcase, "void %s(void) {\n\n%s\n%s}\n", [Test_name, Declaration_section, CUnit_assert]),
    cunit__write_main(Test_suite_name),
    close(testcase).

% IDEA: Split main function string among multiple strings
%% Create the main function for the test suite
cunit__write_main(Test_suite_name) :-
    get_test_folder_path(Path_to_test_directory),
    concat_string([Path_to_test_directory, Test_suite_name, "_main.c"], Filepath_to_main),
    open(Filepath_to_main, write, testcase_main),
    concat_string([Test_suite_name, ".c"], Test_suite_filename),
    cunit__add_test_cases_to_suite(Add_tests_to_suite_string),
    printf(testcase_main, "#include \"%s\"\n\n", [Test_suite_filename]),
    printf(testcase_main, "int main()\n{\n\tif (CUE_SUCCESS != CU_initialize_registry())\n\t\treturn CU_get_error();\n\n\tCU_pSuite pSuite = CU_add_suite(\"Suite_1\", NULL, NULL);\n\tif (NULL == pSuite) {\n\t\tCU_cleanup_registry();\n\t\treturn CU_get_error();\n\t}\n\n%s\n\tCU_basic_set_mode(CU_BRM_VERBOSE);\n\tCU_basic_run_tests();\n\tCU_cleanup_registry();\n\treturn CU_get_error();\n}\n", [Add_tests_to_suite_string]),
    close(testcase_main).

cunit__add_test_cases_to_suite(Add_all_test_cases_to_suite_string) :-
    get_test_cases(Tests),
    cunit__add_test_cases_to_suite(Tests, "", Add_all_test_cases_to_suite_string).
cunit__add_test_cases_to_suite([], Add_to_suite_accumulator, Add_to_suite_accumulator).
cunit__add_test_cases_to_suite([Test_case|More_test_cases], Add_to_suite_accumulator, Add_all_test_cases_to_suite_string) :-
    sprintf(Accumulator_with_current_test_case, "%s\tif (NULL == CU_add_test(pSuite, \"test case\", %s)) {\n\t\tCU_cleanup_registry();\n\t\treturn CU_get_error();\n\t}\n", [Add_to_suite_accumulator, Test_case]),
    cunit__add_test_cases_to_suite(More_test_cases, Accumulator_with_current_test_case, Add_all_test_cases_to_suite_string).

cunit__create_assert(Function_name, Params, Return_value, Return_type, CUnit_assert) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    var_names_as_parameters(Params, "", Var_names),
    sprintf(CUnit_assert, "\tCU_ASSERT(%s(%s) == %s);\n", [Function_name, Var_names, Return_value_as_string]).

% FIXME: I imagine this is possible to be written without the use of an if
%% Checks if this is the first test case being generated.
%% This is to prevent the inclusion of the CUnit header files multiple times
%% in the same file due to backtracking
cunit__is_first_test(Filename) :-
    % The check for file size prevents read_string
    % from prompting for the amount of characters to read
    % incase the file is empty/does not exist
    (
        exists(Filename), get_file_info(Filename, size, File_size), File_size > 0 ->
            open(Filename, read, testcase_read),

            % TODO: Read only the first line, instead of all characters
            read_string(testcase_read, _, First_chars),
            close(testcase_read),
            not string_contains(First_chars, "CUnit/Basic.h")
        ;
            true
    ).

%% The test include files. Called if it is the first test case
cunit__write_test_include(C_filename) :-
    printf(testcase, "#include \"CUnit/Basic.h\"\n", []),
    printf(testcase, "#include \"%s.c\"\n\n", [C_filename]).


%% Check if a string contains a substring
%% Original:The string to check if it contains the substring
%% Substring: The string to be checked if contained within the first parameter
string_contains(Original, Substring) :-
    sub_string(Original, _, _, _, Substring),
    !. % Stop on the first find. Interested exclusively if a substring exists

%% Gets the current test name, as a string
%% Returns "test_{id}"
%% Eg: "test_12" (for the 12th test case)
get_test_name(Test_name) :-
    getval(test_id,Current_id),
    New_id is Current_id + 1,
    set_test_id(New_id),
    term_string(Current_id, Current_id_as_string),
    concat_string(["test_", Current_id_as_string], Test_name),
    append_tests_cases(Test_name).

%% Sets a new test id
set_test_id(New_id) :-
    setval(test_id, New_id).

%% Adds to the current list of all test cases. This is used in the generation
%% of the 'main' CUnit function
append_tests_cases(New_case) :-
    get_test_cases(All_tests),
    append(All_tests, [New_case], New_test_cases),
    set_test_cases(New_test_cases).

%% Updates the test cases in the internal database
set_test_cases(New_cases) :-
    setval(tests,New_cases).

%% Returns the test cases in the internal database
get_test_cases(New_cases) :-
    getval(tests, New_cases).

%% Gets the path to the test folder
get_test_folder_path(Folder_path) :-
    getval(test_folder_path, Folder_path).

%% Create a singular, comma-separated string, of the variables names
%% Params: The list of parameters
%% Variable_name_accumulator: The accumulator for the variable names, as a continuous string
%% All_variable_names: The variable that will be instantiated with the final string
%% Eg: var_names_as_parameters(
%%      [declaration(int, [LC_x{"x"}]),declaration(int, [LC_y{"y"}])],
%%      "", All_variable_names
%%     )
%%
%%  -> All_variable_names = "x,y"
var_names_as_parameters([], Variable_name_accumulator, All_variable_names) :-
    utils__strip_right_comma(Variable_name_accumulator, All_variable_names).
var_names_as_parameters([declaration(int, [H|_])|T], Variable_name_accumulator, All_variable_names) :-
    c_var__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
    var_names_as_parameters(T, Result, All_variable_names).
var_names_as_parameters([declaration(intpointer, [H|_])|T], Variable_name_accumulator, All_variable_names) :-
    c_array__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
    var_names_as_parameters(T, Result, All_variable_names).
var_names_as_parameters([declaration(charpointer, [H|_])|T], Variable_name_accumulator, All_variable_names) :-
    c_array__get_name(H, Var_name),
    sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
    var_names_as_parameters(T, Result, All_variable_names).

create_declaration_section([], Accumulator, Accumulator).
create_declaration_section([declaration(_, [Variable|_])|T], Declaration_accumulator, All_declarations) :-
    c_var__create_declaration(Variable,Declaration),
    sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
    create_declaration_section(T, Result, All_declarations).
create_declaration_section([declaration(_, [Variable|_])|T], Declaration_accumulator, All_declarations) :-
    %FIXME: Below predicate will be broken since changes to internal structures of attributed variable
    c_array__create_declaration(Variable,Declaration),
    sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
    create_declaration_section(T, Result, All_declarations).

create_return(Return_value, int, Return_value_as_string) :-
    term_string(Return_value, Return_value_as_string).
create_return(Return_value, char, Return_value_as_string) :-
    string_codes(Value_as_string, [Return_value]),
    concat_string(["'", Value_as_string, "'"], Return_value_as_string).


% <== Below are all Google Test related predicates ==>

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
