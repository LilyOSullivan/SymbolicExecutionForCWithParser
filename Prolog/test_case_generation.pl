% IDEA: The test-case outputs likely either needs to be in it's own directory, or
%       in the same directory as the .C file(s).

% IDEA: In the interest of efficiency, some of the below printf's could be merged.
%       Flush isn't called, not every print is a OS write call. Likely not too inefficient.

% QUESTION: Does a #include for the original C file need to be placed into the test case?

write_test_cases(Function_name,[void],_) :-
    write("No test cases to generate for "),
    writeln(Function_name),
    !.

write_test_cases(Function_name,Params,Return_value) :-
    concat_string([Function_name,"_tests"],Test_suite_name),
    concat_string([Test_suite_name,".cpp"],Test_suite_filename),
    open(Test_suite_filename, append,testcase),
    open(Test_suite_filename, read,testcase_read),
    (check_if_include_needed ->
            write_test_include
        ;
            % Put a new line to space out the test cases instead of being on the same line as each other
            printf(testcase,"\n",[])
    ),
    printf(testcase,"TEST(",[]),
    printf(testcase,Test_suite_name,[]),
    %TODO: XX shouldn't be a test name below, likely needing a retract ID value, or randomly generated.
    % Random could have collisions
    printf(testcase,",XX) {\n",[]),
    write_assert(Function_name,Params,Return_value),
    printf(testcase,"}\n",[]),
    close(testcase),
    close(testcase_read).

write_assert(Function_name,Params,Return_value) :-
    printf(testcase,"\tASSERT_EQ(",[]),
    printf(testcase,Function_name,[]),
    printf(testcase,"(",[]),
    params_to_string(Params,"",Out),
    printf(testcase,Out,[]),
    printf(testcase,"),",[]),
    term_string(Return_value,Return_value_as_string),
    printf(testcase,Return_value_as_string,[]),
    printf(testcase,");\n",[]).

%% Returns the Parameters as a string to be printed
params_to_string([],_,_).
params_to_string([declaration(int,[H|_])|T],X,Out) :- % The value X here is a WIP
    term_string(H,Int_as_string),
    string_concat(X,Int_as_string,Result),
    Out = Result,
    params_to_string(T,X,Result).
    % TODO: Handle Array Output
    % Not sure how to handle arrays being passed, possibly like
    % &([1,2,3])
    % If so, how does the array get deleted? I think it needs a delete[] (C Equivalent) call

%% Check if the test includes are needed
%% This is primarily for backtracking not to write includes multiple times
check_if_include_needed :-
    read_string(testcase_read, 25, First_chars),
    not string_contains(First_chars,"<gtest/gtest.h>").
    % IDEA: It may be possible to allow multiple includes by using #include_once

%% Chek if a string contains a substring
string_contains(Original,Substring) :-
    sub_string(Original, _,_,_, Substring),
    !. % Stop on the first find. Interested exclusively if a substring exists

%% Write out any includes necessary for the test suite
%% Necessary to ensure the gtest comes first
%% Due to a check for the necessity of writing an include checking for gtest
%% As a first line in the file
write_test_include :-
    printf(testcase,"#include <gtest/gtest.h>\n",[]).