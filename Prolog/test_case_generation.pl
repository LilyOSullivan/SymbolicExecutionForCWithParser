:- use_module(c_var).

%% Generate multiple test cases through failing backtrack
write_test_case_all(Filename, Function_name, Params, Return_value, Return_type) :-
    write_test_case(Filename, Function_name, Params, Return_value, Return_type),
    fail.

%% Generate a singular test case
write_test_case(Filename, Function_name, Params, Return_value, Return_type) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Function_name, "_tests"], Test_suite_name),
    concat_string([Path_to_test_directory, Test_suite_name, ".c"], Test_suite_filepath),
    (is_first_test(Test_suite_filepath) ->
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
    once create_assert(Function_name, Params, Return_value, Return_type, Assert),
    get_test_name(Test_name),
    printf(testcase, "void %s(void) {\n%s%s}\n", [Test_name, Declaration_section, Assert]),
    write_main(Test_suite_name),
    close(testcase).

%% Create the main function for the test suite
write_main(Test_suite_name) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Path_to_test_directory, Test_suite_name, "_main.c"], Filepath_to_main),
    concat_string([Test_suite_name, ".c"], Test_suite_filename),
    write_calls_to_test_cases(Add_tests_to_suite_string),
    open(Filepath_to_main, write, testcase_main),
    printf(testcase_main, "#include \"%s\"\n\n", [Test_suite_filename]),
    printf(testcase_main, "int main()\n{\n%s\n\treturn 0;\n}\n", [Add_tests_to_suite_string]),
    close(testcase_main).

%% Creates the code to call all the test cases
%% The only parameter is the string to be returned
write_calls_to_test_cases(Add_all_test_cases_to_suite_string) :-
    getval(tests, Tests),
    write_calls_to_test_cases(Tests, "", Add_all_test_cases_to_suite_string).
write_calls_to_test_cases([], Add_to_suite_accumulator, Add_to_suite_accumulator).

%% Adds test cases to the test suite. This is the predicate that performs the operation
%% of add_test_cases_to_suite/1
write_calls_to_test_cases([Test_case | More_test_cases], Add_to_suite_accumulator, Add_all_test_cases_to_suite_string) :-
    sprintf(Accumulator_with_current_test_case, "%s\t%s();\n", [Add_to_suite_accumulator, Test_case]),
    write_calls_to_test_cases(More_test_cases, Accumulator_with_current_test_case, Add_all_test_cases_to_suite_string).

%% Creates the assert statement that performs unit-testing
create_assert(Function_name, [void], Return_value, Return_type, Assert) :-
    breal(Return_value),
    sprintf(Function_call_return_value, "%a_return_value", [Function_name]),
    sprintf(Call_function,"\t%a %s = %a();\n",[Return_type, Function_call_return_value, Function_name]),
    util__get_breal_bounds(Return_value, Min, Max),
    sprintf(Assert, "%s\tassert(%s >= %f && %s <= %f);\n", [Call_function, Function_call_return_value, Min, Function_call_return_value, Max]).
create_assert(Function_name, [void], Return_value, Return_type, Assert) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    sprintf(Assert, "\tassert(%s() == %s);\n", [Function_name, Return_value_as_string]).

create_assert(Function_name, Params, Return_value, Return_type, Assert) :-
    breal(Return_value),
    var_names_as_parameters(Params, "", Var_names),
    sprintf(Function_call_return_value, "%a_return_value", [Function_name]),
    sprintf(Call_function, "\t%a %s = %a(%s);\n", [Return_type, Function_call_return_value, Function_name, Var_names]),
    util__get_breal_bounds(Return_value, Min, Max),
    sprintf(Assert, "%s\tassert(%s >= %f && %s <= %f);\n", [Call_function, Function_call_return_value, Min, Function_call_return_value, Max]).

create_assert(Function_name, Params, Return_value, Return_type, Assert) :-
    create_return(Return_value, Return_type, Return_value_as_string),
    var_names_as_parameters(Params, "", Var_names),
    sprintf(Assert, "\tassert(%s(%s) == %s);\n", [Function_name, Var_names, Return_value_as_string]).

%% Checks if this is the first test case being generated.
%% This is to prevent the inclusion of header files multiple times
%% in the same file due to backtracking
is_first_test(Filename) :-
    % The check for file size prevents read_string
    % from prompting for the amount of characters to read
    % incase the file is empty/does not exist
    (
        exists(Filename), get_file_info(Filename, size, File_size), File_size > 0 ->
            (
                open(Filename, read, testcase_read),
                read_string(testcase_read, 20, First_characters),
                close(testcase_read),
                not string_contains(First_characters, "assert.h")
            )
        ;
            (
                true
            )
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
%%      [declaration(int, [LC_x{"x"}], []),declaration(int, [LC_y{"y"}]), []],
%%      "", All_variable_names
%%     )
%%  -> All_variable_names = "x,y"
var_names_as_parameters([], Variable_name_accumulator, All_variable_names) :-
    utils__strip_right_comma(Variable_name_accumulator, All_variable_names).
var_names_as_parameters([declaration(_, [Variable], []) | More_variables], Variable_name_accumulator, All_variable_names) :-
    c_var__is_variable(Variable),
    !,
    c_var__get_name(Variable, Var_name),
    c_var__get_scope(Variable, Scope),
    (
        Scope = global ->
            (
                var_names_as_parameters(More_variables, Variable_name_accumulator, All_variable_names)
            )
        ;
            (
                sprintf(Result, "%s%s,", [Variable_name_accumulator, Var_name]),
                var_names_as_parameters(More_variables, Result, All_variable_names)
            )
    ).

%% Creates a declaration, and assignment, section for variables used in the test cases
%% Params: The list of parameters
%% Declaration_accumulator: The accumulator for the declarations, as a continuous string
%% All_declarations: The variable that will be instantiated with the final string
%% Eg: create_declaration_section(
%%      [declaration(int, [LC_x{"x"}], []), declaration(int, [LC_y{"y"}, []])], Declaration_section)
%%  -> All_declarations = "int x = 5;\nint y = -2;\n"
create_declaration_section([void], "").
create_declaration_section(Declarations, Declaration_section) :-
    create_declaration_section(Declarations, "", All_declarations),
    concat_string(["\n", All_declarations, "\n"], Declaration_section).

create_declaration_section([], Declaration_accumulator, Declaration_accumulator).
create_declaration_section([declaration(_, [Variable], _) | More_variables], Declaration_accumulator, All_declarations) :-
    create_declaration(Variable, Declaration),
    sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
    create_declaration_section(More_variables, Result, All_declarations),
    !.

%% Creates a declaration in C for the c_var
create_declaration(Variable, Declaration) :-
    c_var__is_variable(Variable),
    c_var__get_in_var(Variable, Ptc_in_var),
    c_var__get_type(Variable, Type),
    c_var__get_name(Variable, Var_name),
    c_var__get_scope(Variable, Scope),
    (
        c_var__is_pointer(Variable) ->
            c_var__get_pointer_base_type(Variable, Base_type),
            get_number_of_pointers(Variable, Number_of_pointers),
            get_pointer_value(Variable, Number_of_pointers, Pointer_value),
            c_var__get_out_var(Pointer_value, Pointer_value_out),
            determine_variable_value(Pointer_value_out, Variable_value, Base_type),

            %TODO: This does not account for scope
            generate_pointer_declaration(Base_type, Number_of_pointers, Variable_value, Var_name, Declaration)
        ;
            determine_variable_value(Ptc_in_var, Variable_value, Type),
            generate_declaration(Scope, Type, Var_name, Variable_value, Declaration)
    ),
    !.

%% Create the appropriate value for the variable, based on its type
determine_variable_value(Ptc_in_var, Variable_value, Type) :-
    (integer(Ptc_in_var) ->
        (
            (Type = char ->
                (Ptc_in_var >= 32, Ptc_in_var =< 126 ->
                    (
                        %% Check if Return_value is a single quote
                        (Ptc_in_var =:= 39 ->
                            (
                                Variable_value = "'\\''"
                            )
                        ;
                        Ptc_in_var =:= 92 ->
                            (
                                Variable_value = "'\\\\'"
                            )
                        ;
                            (
                                string_codes(Value_as_string, [Ptc_in_var]),
                                concat_string(["'", Value_as_string, "'"], Variable_value)
                            )
                        )
                    )
                ;
                    (
                        term_string(Ptc_in_var, Variable_value)
                    )
                )
            ;
                Variable_value = Ptc_in_var
            )
        )
    ;
        (
            (breal(Ptc_in_var) ->
                (
                    ptc_solver__label_reals([Ptc_in_var], [Float_labelled]),
                    utils__round_real(Float_labelled, 3, Variable_value)
                )
            )
        )
    ).

%% Generate the declaration string based on scope, type, variable name and value
generate_declaration(Scope, Type, Var_name, Value, Declaration) :-
    (
        float(Value) ->
            (
                Scope = global ->
                    sprintf(Declaration, "\t%s = %f;\n", [Var_name, Value])
                ;
                    sprintf(Declaration, "\t%s %s = %f;\n", [Type, Var_name, Value])
            )
        ;
        string(Value) ->
            (
                Scope = global ->
                    sprintf(Declaration, "\t%s = %s;\n", [Var_name, Value])
                ;
                    sprintf(Declaration, "\t%s %s = %s;\n", [Type, Var_name, Value])
            )
        ;
            (
                Scope = global ->
                    sprintf(Declaration, "\t%s = %d;\n", [Var_name, Value])
                ;
                    sprintf(Declaration, "\t%s %s = %d;\n", [Type, Var_name, Value])
            )
    ).

create_return(Return_value, Type, Return_value_as_string) :-
    integer(Return_value),

    (Type = char ->
        %% Check if Return_value is within the printable ASCII range
        %% https://www.ascii-code.com/characters/printable-characters
        (Return_value >= 32, Return_value =< 126 ->
            (
                %% Check if Return_value is a single quote
                (Return_value =:= 39 ->
                    (
                        Return_value_as_string = "'\\''"
                    )
                ;
                Return_value =:= 92 ->
                    (
                        Return_value_as_string = "'\\\\'"
                    )
                ;
                    (
                        string_codes(Value_as_string, [Return_value]),
                        concat_string(["'", Value_as_string, "'"], Return_value_as_string)
                    )
                )
            )
        ;
            (
                term_string(Return_value, Return_value_as_string)
            )
        )
    ;
        term_string(Return_value, Return_value_as_string)
    ),
    !.

create_return(Return_value, _Type, Return_value_as_string) :-
    float(Return_value),
    term_string(Return_value, Return_value_as_string),
    !.

%% Dereference a pointer to get it's value.
get_pointer_value(Variable, 0, Variable).
get_pointer_value(Variable, Number_of_pointers, Variable_value) :-
    Number_of_pointers > 0,
    evaluate_expression(dereference(Variable), Dereferenced_variable),
    New_number_of_pointers is Number_of_pointers - 1,
    get_pointer_value(Dereferenced_variable, New_number_of_pointers, Variable_value).

% Function to generate C pointer declaration
generate_pointer_declaration(Type, Num_Pointers, Pointer_Value, Top_Level_Pointer, Result_String) :-
    % Generate the name for the initial value
    sprintf(Initial_Value_Name, "pointer_value_%d", [Pointer_Value]),
    % Generate the string for the initial value declaration
    sprintf(Initial_Declaration, "\t%s %s = %d;\n", [Type, Initial_Value_Name, Pointer_Value]),
    % Generate the pointer declarations
    Remaining_Pointers is Num_Pointers - 1,
    generate_pointer_indirections(Type, Remaining_Pointers, Initial_Value_Name, Initial_Declaration, 1, Result_String, Top_Level_Pointer).

% Function to recursively generate pointer declarations
generate_pointer_indirections(Type, Num_Pointers, Current_Pointer, Current_String, Num_Asterisks, Result_String, Top_Level_Pointer) :-
    % Generate the name for the new pointer
    (Num_Pointers = 0 ->
        New_Pointer_Name = Top_Level_Pointer
    ;
        generate_pointer_name(Num_Pointers, New_Pointer_Name)
    ),
    % Generate the string of asterisks for the new pointer declaration
    generate_asterisks_string(Num_Asterisks, Asterisks_String),
    % Generate the string for the new pointer declaration
    sprintf(Pointer_Declaration, "\t%s%s %s = &%s;\n", [Type, Asterisks_String, New_Pointer_Name, Current_Pointer]),
    % Concatenate the current string with the new pointer declaration
    concat_string([Current_String, Pointer_Declaration], Updated_String),
    (Num_Pointers = 0 ->
        % If no more pointers are needed, the result is the updated string
        Result_String = Updated_String
    ;
        % If more pointers are needed, recursively generate the remaining pointer declarations
        Remaining_Pointers is Num_Pointers - 1,
        New_Num_Asterisks is Num_Asterisks + 1,
        generate_pointer_indirections(Type, Remaining_Pointers, New_Pointer_Name, Updated_String, New_Num_Asterisks, Result_String, Top_Level_Pointer)
    ).

% Function to generate a name for a pointer based on the remaining number of pointers
generate_pointer_name(Remaining_Pointers, Pointer_Name) :-
    number_string(Remaining_Pointers, Remaining_Pointers_String),
    concat_string(["pointer", Remaining_Pointers_String], Pointer_Name).

% Function to generate a string of asterisks for a pointer declaration
generate_asterisks_string(Count, Asterisks_String) :-
    length(L, Count),
    maplist(=("*"), L),
    concat_string(L, Asterisks_String).

%% get_number_of_pointers/2
%% get_number_of_pointers(+Variable, -Number_of_pointers)
%% Gets the number of pointer indirection in a variable's type
%% Parameters:
%% Variable: The variable to get the number of indirections from
%% Number_of_pointers: The number of pointer indirections
%% Eg: get_number_of_pointers(LC_x_83{"x"}, Result) -> Result = 2 (Assuming type intpointerpointer)
get_number_of_pointers(Variable, Number_of_pointers) :-
    c_var__get_type(Variable, Type),
    sub_atom(Type, After, _, _, 'pointer'),
    atom_length(Type, Type_length),
    Sub_atom_length is Type_length - After,
    %Count the number of 'pointer' occurrences in the type-atom
    sub_atom(Type, After, Sub_atom_length, _, Sub_atom),
    atom_length(Sub_atom, Length),
    Number_of_pointers is Length div 7.