// Ensures that char underflow is handled correctly

char char_underflow(void) {
    char c = -128 - 1; // 127
    return c;
}