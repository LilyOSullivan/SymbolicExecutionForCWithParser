// Test pointer dereferencing

int pointer_dereference(void) {
    int five = 5;
    int* int_pointer = &five;
    int** int_pointer_pointer = &int_pointer;
    return **int_pointer_pointer;
}