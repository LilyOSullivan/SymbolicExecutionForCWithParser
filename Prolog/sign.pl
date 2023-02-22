parsed([
    function_definition(give_five, [void], [return(5)], int),
    function_definition(check_return, [
    declaration(int, [LC_x]) ], [
    function_call(give_five, []),
    if_statement(39, expression(
    function_call(give_five, [])+LC_x==7), [return(1)], [return(0)])], int),

    global_variables(999, 999)

    ]).