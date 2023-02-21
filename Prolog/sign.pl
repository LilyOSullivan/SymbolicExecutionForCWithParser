parsed([
    function_definition(give_five, [
    declaration(int, [LC_a]) ], [return(LC_a)], int),
    function_definition(check_return, [
    declaration(int, [LC_y]),
    declaration(int, [LC_x]),
    declaration(int, [LC_z]) ], [
    declaration(int, [LC_five_37]),
    init_record(LC_five_37 ,
    function_call(give_five, [LC_x])),return(LC_y+LC_x+LC_z+LC_five_37)
    ], int),

    global_variables(999, 999)

    ]).