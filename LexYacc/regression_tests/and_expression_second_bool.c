// Ensure the first 'and' argument is not always selected in 'and' statement
// The first expression and subsequent expressions must hold true

int and_expression_second_bool(int x) {
    if(x != 0) {
        if(x > 0 && x == 5 && x != 99) {
            return 5;
        }
    } else {
        return 0;
    }

    return -1;
}