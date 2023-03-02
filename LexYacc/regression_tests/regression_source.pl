parsed([
function_definition(equals_expression, [
declaration(int, [LC_x]) ], [
assignment(LC_x , (
assignment(LC_x , 2))+1), return(LC_x)], int),
function_definition(is_five, [
declaration(int, [LC_x]) ], [
if_statement(17, expression(LC_x==5), [return(1)], []), return(0)], int),

global_variables([
declaration(int, [LC_y_17]),
assignment(LC_y_17 , 5) ], void),

function_definition(check_global, [void], [return(LC_y_17)], int),

global_variables(999, 999)

]).