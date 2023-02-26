parsed([
    function_definition(LC_fib, [
    declaration(int, [LC_n]) ], [
    if_statement(40, expression(LC_n<=1), [return(LC_n)], []), return(
    function_call(LC_fib, [LC_n-1])+
    function_call(LC_fib, [LC_n-2]))], int),
    function_definition(LC_fib_helper, [
    declaration(int, [LC_x]) ], [
    if_statement(45, expression(LC_x==9), [return(
    function_call(LC_fib, [5])+
    function_call(LC_fib, [7]))], []), return(0)], int),

    global_variables(999, 999)

    ]).