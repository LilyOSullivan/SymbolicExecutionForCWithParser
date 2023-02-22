parsed([
    function_definition(inc, [
    declaration(int, [LC_a]) ], [
    assignment(LC_a , LC_a/2), return(LC_a+2-1/2)], int),
    function_definition(check_return, [
    declaration(int, [LC_y]),
    declaration(int, [LC_x]),
    declaration(int, [LC_z]) ], [
    if_statement(39, expression(andop(andop(LC_y>0 , LC_x<0) , LC_z==91)), [
    declaration(int, [LC_incremented_39]),
    init_record(LC_incremented_39 ,
    function_call(inc, [LC_x])),return(LC_y+LC_x+LC_z+LC_incremented_39)
    ], []), return((-123))], int),

    global_variables(999, 999)

    ]).