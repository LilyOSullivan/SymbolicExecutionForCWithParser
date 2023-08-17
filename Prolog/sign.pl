parsed([
    function_definition(LC_pointer_dereference, [void], [
    declaration(int, [LC_five_4], [
    assignment(LC_five_4 , 5)]),
    declaration(intpointer , [LC_int_pointer_4], [
    assignment(LC_int_pointer_4 , address_of(LC_five_4))]),
    declaration(intpointerpointer , [LC_int_pointer_pointer_4], [
    assignment(LC_int_pointer_pointer_4 , address_of(LC_int_pointer_4))]),return(dereference(dereference(LC_int_pointer_pointer_4)))], int),

    global_variables(999, 999)

    ]).