// Ensure the first 'or' argument is not always selected in 'or' statement
// The first expression is allowed to be false if the need arises if a
// a subsequent expression is true

int or_expression_second_bool(int x) {
    if(x != 0) {
        if(x == 0 || x == 1) {
            return 1;
        }
    } else {
        return 0;
    }

    return -1;
}