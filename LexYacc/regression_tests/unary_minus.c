// Test unary minus (negative) operator as expression and as a statement
int unary_minus(int x) {
    -x;
    if(x != 0) {
        return -x;
    } else {
        return x;
    }
}
