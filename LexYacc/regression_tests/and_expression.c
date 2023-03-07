// Test chained 'and' expressions

int and_expression(int x) {
    if(x != 0 && x != 1 && x != 2 && x != -1) {
        return x;
    }
    return 0;
}