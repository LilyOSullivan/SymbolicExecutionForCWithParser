:- use_module(c_var).

%% Generate a test case with failing backtrack
write_test_case(Filename, Function_name, Params, Return_value, Return_type) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Function_name, "_tests"], Function_name_with_test_prefix),
    concat_string([Path_to_test_directory, Function_name_with_test_prefix, ".c"], Test_case_filepath),
    (is_first_test(Test_case_filepath) ->
            setup_test_cases_file(Path_to_test_directory, Test_case_filepath, Filename)
    ;
            open(Test_case_filepath, append, testcase)
    ),
    write_test_case_to_file(Function_name, Params, Return_value, Return_type),
    close(testcase),
    write_main(Function_name_with_test_prefix),
    fail.

%% Setup a test case file for a first time run  with the appropriate header files
setup_test_cases_file(Path_to_test_directory, Test_case_filepath, Filename) :-
    mkdir(Path_to_test_directory),
    open(Test_case_filepath, append, testcase),
    printf(testcase, "#include \"assert.h\"\n", []),
    printf(testcase, "#include \"../%s.c\"\n\n", [Filename]).

%% Create the test case
write_test_case_to_file(Function_name, Params, Return_value, Return_type) :-
    create_assert(Function_name, Params, Return_value, Return_type, Assert),
    increment_and_get_test_id(Test_id),
    create_declaration_section(Params, Declaration_section),
    printf(testcase, "void test_%d(void) {\n%s%s}\n\n", [Test_id, Declaration_section, Assert]).

%% Create the main function for the test cases
write_main(Function_name_with_test_prefix) :-
    getval(test_folder_path, Path_to_test_directory),
    concat_string([Path_to_test_directory, Function_name_with_test_prefix, "_main.c"], Filepath_to_main),
    create_calls_to_test_cases(Call_test_cases_string),
    open(Filepath_to_main, write, testcase_main),
    printf(testcase_main, "#include \"%s.c\"\n\n", [Function_name_with_test_prefix]),
    printf(testcase_main, "int main()\n{\n%s\n\treturn 0;\n}\n", [Call_test_cases_string]),
    close(testcase_main).

%% Creates the code to call all the test cases
%% The only parameter is the string to be returned
create_calls_to_test_cases(Call_test_cases_string) :-
    getval(test_id, Amount_of_test_cases),
    create_calls_to_test_cases(Amount_of_test_cases, 1, "", Call_test_cases_string).

%% This is the predicate that performs the operation
%% of create_calls_to_test_cases/1
create_calls_to_test_cases(Amount_of_test_cases, Amount_of_test_cases, Call_tests_accumulator, Call_tests_accumulator) :- !.
create_calls_to_test_cases(Amount_of_test_cases, Current_test_id, Call_tests_accumulator, Call_test_cases_string) :-
    sprintf(Accumulator_with_current_test_case, "%s\ttest_%d();\n", [Call_tests_accumulator, Current_test_id]),
    succ(Current_test_id, New_current_test_id),
    create_calls_to_test_cases(Amount_of_test_cases, New_current_test_id, Accumulator_with_current_test_case, Call_test_cases_string).

%% Creates the assert statement that performs unit-testing
create_assert(Function_name, Params, Return_value, Return_type, Assert) :-
    ( Params = [void] -> 
        Parameters = ""
    ;
        var_names_as_parameters(Params, "", Parameters)
    ),
    ( breal(Return_value) -> 
        util__get_breal_bounds(Return_value, Min, Max),
        sprintf(Function_call_return_value, "%a_return_value", [Function_name]),
        sprintf(Call_function, "\t%a %s = %a(%s);\n", [Return_type, Function_call_return_value, Function_name, Parameters]),
        sprintf(Assert, "%s\tassert(%s >= %f && %s <= %f);\n", [Call_function, Function_call_return_value, Min, Function_call_return_value, Max])
    ; 
        determine_variable_value(Return_value, Return_type, Return_value_as_string),
        sprintf(Assert, "\tassert(%s(%s) == %s);\n", [Function_name, Parameters, Return_value_as_string])
    ).

%% is_first_test/1
%% is_first_test(+Filename)
%% Checks if this is the first test case being generated.
%% This is to prevent the inclusion of header files multiple times
%% in the same file due to backtracking
is_first_test(Filename) :-
    exists_file_with_content(Filename),
    !,
    open(Filename, read, Stream),
    read_string(Stream, 20, First_characters),
    close(Stream),
    not utils__string_contains(First_characters, "assert.h").
is_first_test(_).

% Check if a file exists and has any content.
exists_file_with_content(Filename) :-
    exists(Filename),
    get_file_info(Filename, size, File_size),
    File_size > 0.

%% increment_and_get_test_id/1
%% increment_and_get_test_id(-Current_test_id)
%% Gets the current test id and returns it, incrementing it for the next test case
increment_and_get_test_id(Current_test_id) :-
    getval(test_id, Current_test_id),
    succ(Current_test_id, New_test_id),
    setval(test_id, New_test_id).

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
    c_var__get_name(Variable, Var_name),
    c_var__get_scope(Variable, Scope),
    (Scope = global ->
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
create_declaration_section([void], "") :- !.
create_declaration_section(Declarations, Declaration_section) :-
    create_declaration_section(Declarations, "", All_declarations),
    concat_string(["\n", All_declarations, "\n"], Declaration_section).

create_declaration_section([], Declaration_accumulator, Declaration_accumulator).
create_declaration_section([declaration(_, [Variable], _) | More_variables], Declaration_accumulator, All_declarations) :-
    create_declaration(Variable, Declaration),
    sprintf(Result, "%s%s", [Declaration_accumulator, Declaration]),
    create_declaration_section(More_variables, Result, All_declarations).

%% Creates a declaration in C for the c_var
create_declaration(Variable, Declaration) :-
    c_var__get_in_var(Variable, Ptc_in_var),
    c_var__get_type(Variable, Type),
    c_var__get_name(Variable, Var_name),
    c_var__get_scope(Variable, Scope),
    (c_var__is_pointer(Variable) ->
    get_number_of_pointers(Variable, Number_of_pointers),
    get_pointer_value(Variable, Number_of_pointers, Pointer_value),
    c_var__get_pointer_base_type(Variable, Base_type),
        c_var__get_in_var(Pointer_value, Pointer_value_in),
        determine_variable_value(Pointer_value_in, Variable_value, Base_type),

        %TODO: This does not account for scope
        generate_pointer_declaration(Base_type, Number_of_pointers, Variable_value, Var_name, Declaration)
    ;
        determine_variable_value(Ptc_in_var, Type, Variable_value),
        generate_declaration(Scope, Type, Var_name, Variable_value, Declaration)
    ),
    !.

%% Create the appropriate value for the variable, based on its type
determine_variable_value(Ptc_in_var, char, Variable_value) :-
    integer(Ptc_in_var),
    %% Check if Return_value is within the printable ASCII range
    %% https://www.ascii-code.com/characters/printable-characters
    Ptc_in_var >= 32, 
    Ptc_in_var =< 126,
    !,
    char_value(Ptc_in_var, Variable_value).

determine_variable_value(Ptc_in_var, _, Variable_value) :-
    integer(Ptc_in_var),
    !,
    % convert an integer to a string
    number_string(Ptc_in_var, Variable_value).

determine_variable_value(Ptc_in_var, _, Variable_value)  :-
    breal(Ptc_in_var),
    !,
    % The value is already labelled, this s just to get the value of the variable
    ptc_solver__label_reals([Ptc_in_var], [Float_labelled]), 
    utils__round_real(Float_labelled, 3, Variable_value).

determine_variable_value(Ptc_in_var, _, Variable_value)  :-
    breal(Ptc_in_var),
    !,
    ptc_solver__label_reals([Ptc_in_var], [Float_labelled]),
    utils__round_real(Float_labelled, 3, Variable_value).

determine_variable_value(Ptc_in_var, _, Variable_value)  :-
    float(Ptc_in_var),
    !,
    term_string(Ptc_in_var, Variable_value).

% Helper to convert character values into their respective strings.
char_value(39, "'\\''").   % Single quote
char_value(92, "'\\\\'").  % Backslash
char_value(Integer_value, Variable_value) :-   % Any other character
    sprintf(Variable_value, "'%c'", [Integer_value]).

%% Generate the declaration string based on scope, type, variable name and value
generate_declaration(global, _, Var_name, Value, Declaration) :-
    format_string(Value, Format),
    concat_string(["\t%s = ", Format, ";\n"], Pattern),
    sprintf(Declaration, Pattern, [Var_name, Value]),
    !.

generate_declaration(_, Type, Var_name, Value, Declaration) :-
    format_string(Value, Format),
    concat_string(["\t%s %s = ", Format, ";\n"], Pattern),
    sprintf(Declaration, Pattern, [Type, Var_name, Value]).

format_string(Value, "%f") :- float(Value), !.
format_string(Value, "%s") :- string(Value), !.
format_string(_, "%d").

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

%% Predicate to recursively generate pointer declarations
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
        succ(Num_Asterisks, New_Num_Asterisks),
        generate_pointer_indirections(Type, Remaining_Pointers, New_Pointer_Name, Updated_String, New_Num_Asterisks, Result_String, Top_Level_Pointer)
    ).

%% Predicate to generate a name for a pointer based on the remaining number of pointers
generate_pointer_name(Remaining_Pointers, Pointer_Name) :-
    number_string(Remaining_Pointers, Remaining_Pointers_String),
    concat_string(["pointer", Remaining_Pointers_String], Pointer_Name).

%% Predicate to generate a string of asterisks for a pointer declaration
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
    % Count the number of 'pointer' occurrences in the type-atom
    sub_atom(Type, After, Sub_atom_length, _, Sub_atom),
    atom_length(Sub_atom, Length),
    Number_of_pointers is Length div 7.