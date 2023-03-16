:- use_module(c_array).
:- use_module(c_var).


%% Generate multiple test cases through failing backtrack
cunit__write_test_case_all(Filename, Function_name, Params, Return_value, Return_type) :-
    cunit__write_test_case(Filename, Function_name, Params, Return_value, Return_type),
    fail.

%% Generate a singular test case
cunit__write_test_case(Filename, Function_name, Params, Return_value, Return_type) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Function_name, "_tests"], Test_suite_name),
    concat_string([Path_to_test_directory, Test_suite_name, ".c"], Test_suite_filepath),
    (cunit__is_first_test(Test_suite_filepath) ->
        (
            mkdir(Path_to_test_directory),
            open(Test_suite_filepath, append, testcase),
            printf(testcase, "#include \"assert.h\"\n", []),
            printf(testcase, "#include \"../%s.c\"\n\n", [Filename])
        )
    ;
        (
            open(Test_suite_filepath, append, testcase),
            % Put a new line to visually space out the test cases
            printf(testcase, "\n", [])
        )
    ),
    create_declaration_section(Params, Declaration_section),
    cunit__create_assert(Function_name, Params, Return_value, Return_type, CUnit_assert),
    get_test_name(Test_name),
    printf(testcase, "void %s(void) {\n%s%s}\n", [Test_name, Declaration_section, CUnit_assert]),
    cunit__write_main(Test_suite_name),
    close(testcase).

%% Create the main function for the test suite
cunit__write_main(Test_suite_name) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Path_to_test_directory, Test_suite_name, "_main.c"], Filepath_to_main),
    concat_string([Test_suite_name, ".c"], Test_suite_filename),
    cunit__add_test_cases_to_suite(Add_tests_to_suite_string),
    open(Filepath_to_main, write, testcase_main),
    printf(testcase_main, "#include \"%s\"\n\n", [Test_suite_filename]),
    printf(testcase_main, "int main()\n{\n%s\n\treturn 0;\n}\n", [Add_tests_to_suite_string]),
    close(testcase_main).

%% Creates the code to add all test cases to the test suite, for CUnit
%% The only parameter is the string to be returned
cunit__add_test_cases_to_suite(Add_all_test_cases_to_suite_string) :-
    getval(tests, Tests),
    cunit__add_test_cases_to_suite(Tests, "", Add_all_test_cases_to_suite_string).
cunit__add_test_cases_to_suite([], Add_to_suite_accumulator, Add_to_suite_accumulator).

%% Adds test cases to the test suite. This is the predicate that performs the operation
%% of cunit__add_test_cases_to_suite/1
cunit__add_test_cases_to_suite([Test_case | More_test_cases], Add_to_suite_accumulator, Add_all_test_cases_to_suite_string) :-
    sprintf(Accumulator_with_current_test_case, "%s\t%s();\n", [Add_to_suite_accumulator, Test_case]),
    cunit__add_test_cases_to_suite(More_test_cases, Accumulator_with_current_test_case, Add_all_test_cases_to_suite_string).

%% Creates the CUnit assert statement that performs unit-testing
cunit__create_assert(Function_name, [void], Return_value, Return_type, CUnit_assert) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    sprintf(CUnit_assert, "\tassert(%s() == %s);\n", [Function_name, Return_value_as_string]).

cunit__create_assert(Function_name, Params, Return_value, Return_type, CUnit_assert) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    var_names_as_parameters(Params, "", Var_names),
    sprintf(CUnit_assert, "\tassert(%s(%s) == %s);\n", [Function_name, Var_names, Return_value_as_string]).

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
            read_string(testcase_read, 24, First_chars),
            close(testcase_read),
            not string_contains(First_chars, "assert.h")
        ;
            true
    ).

%% Check if a string contains a substring
%% Original:The string to check if it contains the substring
%% Substring: The string to be checked if contained within the first parameter
string_contains(Original, Substring) :-
    once sub_string(Original, _, _, _, Substring).

%% Gets the current test name, as a string
%% Returns "test_{id}"
%% Eg: "test_12" (for the 12th test case)
get_test_name(Test_name) :-
    getval(test_id,Current_id),
    New_id is Current_id + 1,
    setval(test_id, New_id),
    term_string(Current_id, Current_id_as_string),
    concat_string(["test_", Current_id_as_string], Test_name),
    getval(tests, All_tests),
    append(All_tests, [Test_name], New_test_cases),
    setval(tests,New_test_cases).

%% Create a singular, comma-separated string, of the variables
%% Params: The list of parameters
%% Variable_name_accumulator: The accumulator for the variable names, as a continuous string
%% All_variable_names: The variable that will be instantiated with the final string
%% Eg: var_names_as_parameters(
%%      [declaration(int, [LC_x{"x"}]),declaration(int, [LC_y{"y"}])],
%%      "", All_variable_names
%%     )
%%  -> All_variable_names = "x,y"
var_names_as_parameters([], Variable_name_accumulator, All_variable_names) :-
    utils__strip_right_comma(Variable_name_accumulator, All_variable_names).
var_names_as_parameters([declaration(_, [Variable])|More_variables], Variable_name_accumulator, All_variable_names) :-
    c_var__is_variable(Variable),
    !,
    c_var__get_name(Variable, Var_name),
    sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
    var_names_as_parameters(More_variables, Result, All_variable_names).

var_names_as_parameters([declaration(_, [Variable]) | More_variables], Variable_name_accumulator, All_variable_names) :-
    c_array__is_array(Variable),
    !,
    c_array__get_name(Variable, Var_name),
    sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
    var_names_as_parameters(More_variables, Result, All_variable_names).

%% Creates a declaration, and assignment, section for variables used in the test cases
%% Params: The list of parameters
%% Declaration_accumulator: The accumulator for the declarations, as a continuous string
%% All_declarations: The variable that will be instantiated with the final string
%% Eg: create_declaration_section(
%%      [declaration(int, [LC_x{"x"}]), declaration(int, [LC_y{"y"}])], Declaration_section)
%%  -> All_declarations = "int x = 5;\nint y = -2;\n"
create_declaration_section(Declarations, Declaration_section) :-
    create_declaration_section(Declarations, "", All_declarations),
    concat_string(["\n", All_declarations, "\n"], Declaration_section).
create_declaration_section([void], "").
create_declaration_section([], Declaration_accumulator, Declaration_accumulator).
create_declaration_section([declaration(_, [Variable]) | More_variables], Declaration_accumulator, All_declarations) :-
    c_var__create_declaration(Variable, Declaration),
    sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
    create_declaration_section(More_variables, Result, All_declarations),
    !.
% create_declaration_section([declaration(_, [Variable]) | More_variables], Declaration_accumulator, All_declarations) :-
%     c_array__create_declaration(Variable, Declaration),
%     sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
%     create_declaration_section(More_variables, Result, All_declarations),
%     !.

create_return(Return_value, int, Return_value_as_string) :-
    term_string(Return_value, Return_value_as_string).
create_return(Return_value, char, Return_value_as_string) :-
    string_codes(Value_as_string, [Return_value]),
    concat_string(["'", Value_as_string, "'"], Return_value_as_string).
