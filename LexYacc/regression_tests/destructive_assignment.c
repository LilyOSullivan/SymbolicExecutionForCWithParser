// Assignment of a value that is 'non-logical'
// Eg x = x + x

int destructive_assignment(int x, int y) {
    x = x + y;
    if (x > 0) {
        return 1;
    }
    x = x + 1;
    if(x >= 1) {
        return x;
    }
    return 42;
}