// Swaps the values of two variables using pointers

int pointer_change_underlying_value(void) {
    int five = 5;
    int ten = 10;

    int* five_pointer = &five;
    int* ten_pointer = &ten;

    int temp = *five_pointer;
    *five_pointer = *ten_pointer;
    *ten_pointer = temp;

    return five;
}