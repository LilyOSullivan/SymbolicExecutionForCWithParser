// Handle expression statements
// Eg:
//  2/2;
//  2+give_five();
//  2;
//  2+(x=3);

int give_five() {
    return 5;
}

int expression_statements(int x) {
    int y = 8;
    2-x;
    5;
    (x=12345)/2;
    3+give_five();
    return x;
}
