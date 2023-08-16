
char pointer_different_pointer_types(void) {
    char letter_a = 'a';
    int* int_pointer = &letter_a;
    char** char_pointer = &int_pointer;
    return **char_pointer;
}