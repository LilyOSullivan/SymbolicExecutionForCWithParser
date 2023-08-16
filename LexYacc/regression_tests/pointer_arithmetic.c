
int pointer_arithmetic() {
    int five = 5;
    int* five_pointer = &five;

    (*five_pointer)++;
    *five_pointer += 2;
    return *five_pointer;
}