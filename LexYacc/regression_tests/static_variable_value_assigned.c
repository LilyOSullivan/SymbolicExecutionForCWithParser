// Ensures the value of a static variable is assigned correctly, and not just set to zero.

int counter() {
    static int x = 10;
    x++;
    return x;
}

int static_variable_value_assigned() {
    return counter() + counter(); // 11 + 12 = 23
}