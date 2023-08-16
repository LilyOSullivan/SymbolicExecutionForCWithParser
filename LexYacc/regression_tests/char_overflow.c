// Ensures that char overflow is handled correctly

char char_overflow(void) {
    char c = 127 + 1; // -128
    return c;
}