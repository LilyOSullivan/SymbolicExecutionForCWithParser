// An uninitialised static value should have a default value.

int static_default_value() {
    static int y;
    return y;
}