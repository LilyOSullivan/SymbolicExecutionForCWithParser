% QUESTION: The test-case outputs likely either needs to be in it's own directory, or
%       in the same directory as the .C file(s).

% IDEA: In the interest of efficiency, some of the below printf's could be merged.
%       Flush isn't called on every print, likely not too inefficient.

%IDEA: Keep a running counter for the number of tab-indentation's desired

%IDEA: It may be possible to use/return accumulators as-is instead of Out variables

cunit_write_test_case_all(Function_name,Params,Return_value) :-
    cunit_write_test_case(Function_name,Params,Return_value),
    fail.
cunit_write_test_case_all(_Function_name,_Params,_Return_value).

cunit_write_test_case(Function_name,[void],_) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

cunit_write_test_case(Function_name,Params,Return_value) :-
    concat_string([Function_name,"_tests"],Test_suite_name),
    concat_string([Test_suite_name,".c"],Test_suite_filename),
    concat_string([Test_suite_name,"_main.c"],Test_main_file),
    (
        cunit_is_first_test(Test_suite_filename) ->
            open(Test_suite_filename, append,testcase),
            open(Test_suite_filename, read,testcase_read),
            cunit_write_test_include
        ;
            % Put a new line to space out the test cases
            open(Test_suite_filename, append,testcase),
            open(Test_suite_filename, read,testcase_read),
            printf(testcase,"\n",[])
    ),
    open(Test_main_file, write,testcase_main),
    get_test_id(Test_id),
    term_string(Test_id,Test_id_as_string),
    concat_string(["test_",Test_id_as_string],Test_name),
    append_tests_cases(Test_name),
    printf(testcase,"void %s(void) {\n\n",[Test_name]),
    New_test_id is Test_id + 1,
    set_test_id(New_test_id),


    % %%% WRITE DECLARATION SECTION HERE
    create_declaration_section(Params,"",Declaration_section),
    printf(testcase,Declaration_section,[]),
    printf(testcase,"\n",[]),


    cunit_write_cu_assert(Function_name,Params,Return_value),
    printf(testcase,"}\n",[]),
    cunit_write_main(Function_name,Test_suite_filename),
    close(testcase_main),
    close(testcase),
    close(testcase_read).

% IDEA: Split main function string among multiple printf's
cunit_write_main(Function_name,Tests_filename) :-
    cunit_add_test_cases_to_suite(Test_cases_to_add_to_suite),
    printf(testcase_main,"#include \"%s\"\n",[Tests_filename]),

    %HACK: Assuming filename and function-names are the same.
    %      Filenames are not being received from the parser
    concat_string([Function_name,".c"],File_name),
    printf(testcase_main,"#include \"%s\"\n\n",[File_name]),
    printf(testcase_main,"int main()\n{\n   if (CUE_SUCCESS != CU_initialize_registry())\n      return CU_get_error();\n\n   CU_pSuite pSuite = CU_add_suite(\"Suite_1\", NULL, NULL);\n   if (NULL == pSuite) {\n      CU_cleanup_registry();\n      return CU_get_error();\n   }\n\n   %s\n   CU_basic_set_mode(CU_BRM_VERBOSE);\n   CU_basic_run_tests();\n   CU_cleanup_registry();\n   return CU_get_error();\n}\n",[Test_cases_to_add_to_suite]).

%Create a string stream
cunit_add_test_cases_to_suite(Out) :-
    open(string(""), write, add_to_suite),
    get_test_cases(Tests),
    cunit_add_to_suite_loop(Tests),
    set_test_cases(Tests),
    get_stream_info(add_to_suite, name, Out),
    close(add_to_suite).

cunit_add_to_suite_loop([]).
cunit_add_to_suite_loop([Test_case|T]) :-
    printf(add_to_suite,"\tif (NULL == CU_add_test(pSuite, \"test case\", %s)) {\n",[Test_case]),
    printf(add_to_suite,"\t\tCU_cleanup_registry();\n", []),
    printf(add_to_suite,"\t\treturn CU_get_error();\n\t}\n",[]),
    cunit_add_to_suite_loop(T).

%FIXME: I would like the return value to be after the == and function name to be first
%       Eg: CU_ASSERT(function_name(x,y,z) == 0)
cunit_write_cu_assert(Function_name,Params,Return_value) :-
    printf(testcase,"\tCU_ASSERT(",[]),
    term_string(Return_value,Return_value_as_string),
    printf(testcase,Return_value_as_string,[]),
    printf(testcase," == %s(",[Function_name]),
    get_var_names(Params,"",Var_names),
    printf(testcase,Var_names,[]),
    printf(testcase,"));\n",[]).

% FIXME: I imagine this is possible to be written without the use of an if
cunit_is_first_test(Filename) :-
    % The check for file size prevents read_string
    % from prompting for the amount of characters to read
    (
        exists(Filename),get_file_info(Filename,size,File_size),File_size > 0 ->
            open(Filename, read,testcase_read),
            read_string(testcase_read, _, First_chars),
            close(testcase_read),
            not string_contains(First_chars,"CUnit/Basic.h")
        ;
            true
    ).

cunit_write_test_include :-
    printf(testcase,"#include \"CUnit/Basic.h\"\n",[]).
    % printf(testcase,"#include "%s.c"\n",[C_filename]).


gtest_write_test_case_all(Function_name,[void],_) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

gtest_write_test_case_all(Function_name,Params,Return_value) :-
    gtest_write_test_case(Function_name,Params,Return_value),
    fail,
    !.

gtest_write_test_case(Function_name,[void],_) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

gtest_write_test_case(Function_name,Params,Return_value) :-
    concat_string([Function_name,"_tests"],Test_suite_name),
    concat_string([Test_suite_name,".cpp"],Test_suite_filename),
    open(Test_suite_filename, append,testcase),
    open(Test_suite_filename, read,testcase_read),
    (
        gtest_is_first_test ->
            gtest_write_test_include
        ;
            % Put a new line to space out the test cases
            printf(testcase,"\n",[])
    ),
    printf(testcase,"TEST(",[]),
    printf(testcase,Test_suite_name,[]),
    printf(testcase,",",[]),
    get_test_id(Test_id),
    term_string(Test_id,Test_id_as_string),
    printf(testcase,Test_id_as_string,[]),
    printf(testcase,") {\n",[]),
    New_test_id is Test_id + 1,
    set_test_id(New_test_id),
    gtest_write_assert_eq(Function_name,Params,Return_value),
    printf(testcase,"}\n",[]),
    close(testcase),
    close(testcase_read).

gtest_write_assert_eq(Function_name,Params,Return_value) :-
    printf(testcase,"\tASSERT_EQ(",[]),
    printf(testcase,Function_name,[]),
    printf(testcase,"(",[]),
    params_to_string(Params,"",Out),
    printf(testcase,Out,[]),
    printf(testcase,"),",[]),
    term_string(Return_value,Return_value_as_string),
    printf(testcase,Return_value_as_string,[]),
    printf(testcase,");\n",[]).

%% Check if the test includes are needed
%% This is primarily for backtracking not to write includes multiple times
gtest_is_first_test :-
    read_string(testcase_read, 25, First_chars),
    not string_contains(First_chars,"<gtest/gtest.h>").


%% Write out any includes necessary for the test suite
%% Necessary to ensure the gtest comes first
%% Due to a check for the necessity of writing an include checking for gtest
%% As a first line in the file
gtest_write_test_include :-
    printf(testcase,"#include <gtest/gtest.h>\n",[]).
    % printf(testcase,"#include "%s.c"\n",[C_filename]).


%% Check if a string contains a substring
string_contains(Original,Substring) :-
    sub_string(Original, _,_,_, Substring),
    !. % Stop on the first find. Interested exclusively if a substring exists

get_test_id(Out) :-
    retract(test_id(Out)),
    !.

set_test_id(New_id) :-
    asserta(test_id(New_id)).

append_tests_cases(New_case) :-
    get_test_cases(All_tests),
    append(All_tests,[New_case],New_test_cases),
    set_test_cases(New_test_cases).

set_test_cases(New_cases) :-
    asserta(tests(New_cases)).

get_test_cases(New_cases) :-
    retract(tests(New_cases)),
    !.

params_to_var_names([],Accumulator,Out) :-
    strip_right_comma(Accumulator,Out).
params_to_var_names([declaration(_,[H|_])|T],Accumulator,Out) :-
    var_names(H,Var_name),
    string_concat(Accumulator,Var_name,Result),
    string_concat(Result,",",Result_with_comma),
    params_to_var_names(T,Result_with_comma,Out).

%IDEA: There could be a second function to remove the if, to simply be Out = In.
%      Prolog will go to the alternative function when backtracking, however
%      a choice point will be created, I do not want a choice point here, not
%      a desire to use a cut
%% Removes the last character if it is a comma
strip_right_comma(In,Out) :-
    (
        sub_string(In,_,1,0,",") ->
            sub_string(In,0,_,1,Out)
        ;
            Out = In
    ).

get_var_names([],Accumulator,Out) :-
    strip_right_comma(Accumulator,Out).
get_var_names([declaration(_,[H|_])|T],Accumulator,Out) :-
    get_var_name(H,Var_name),
    string_concat(Accumulator,Var_name,Result),
    string_concat(Result,",",Result_with_comma),
    get_var_names(T,Result_with_comma,Out).

% Below modified from
% https://stackoverflow.com/a/61809974
reduce(_, [],  Default, Default).
reduce(_, [A], _, A).
reduce(P3, [A,B|T], _, D):-
    call(P3, A, B, C),
    reduce(P3, [C|T], _, D),!.

%IDEA: Some of the below concat's could be merged together
create_declaration_section([],Accumulator,Out) :-
    Out = Accumulator.
create_declaration_section([declaration(_,[H|_])|T],Accumulator,Out) :-
    get_c_var(H,{Type,Var,Var_name}),
    get_declaration_components(Type,Var,Type_declaration,Value_declaration),
    string_concat(Accumulator,"\t",Result),
    string_concat(Result,Type_declaration,Result2),
    string_concat(Result2," ",Result3),
    string_concat(Result3,Var_name,Result4),
    string_concat(Result4," = ",Result5),
    string_concat(Result5,Value_declaration,Result6),
    string_concat(Result6,";\n",Result7),
    create_declaration_section(T,Result7,Out).

get_declaration_components(int,Var,Type_declaration,Value_declaration) :-
    Type_declaration = "int ",
    term_string(Var,Value_declaration).


get_declaration_components(intpointer,Var,Type_declaration,Value_declaration) :-
    Type_declaration = "int[5] ",
    ptc_solver__get_array_index_elements(Var, Indexs),
    get_all_array_inputs(Indexs, Values),
    ( foreach(Value, Values), foreach(X, Values_as_string) do
        term_string(Value,Value_as_string),
        string_concat(Value_as_string,",",X)
    ),
    reduce(string_concat, Values_as_string, "", Result),
    strip_right_comma(Result,Value_declaration).

% Unused, this provides a fallback
get_type_declaration(Type,Var,Type_declaration,Value_declaration) :-
    term_string(Type,Type_declaration),
    term_string(Var,Value_declaration).


