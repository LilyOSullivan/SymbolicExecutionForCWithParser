// The value of a static variable should be preserved between calls.

int counter() {
    static int x = 0; // The value is zero by default, being explicit for clarity
    x++;
    return x;
}

int static_persist_value() {
    return counter() + counter() + counter(); // 1 + 2 + 3 = 6
}