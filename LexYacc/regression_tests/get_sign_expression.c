int get_sign_expression(int x) {
    if (x==0) return 0+x;
    if (x>0) return 1+x;
    return -1-x;
}