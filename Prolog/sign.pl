parsed([
    function_definition(LC_get_sign, [
    declaration(int, [LC_x]) ], [
    if_statement(78, expression(LC_x==0), [return(0)], []),
    if_statement(77, expression(LC_x>0), [return(1)], []), return((-1))], int),

    global_variables(999, 999)

    ]).