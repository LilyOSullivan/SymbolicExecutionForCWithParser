// Prioritise local scope over global scope. This is primarily a test of the
// parser than the test-driver.
// The actual C-return is -99

int x = 1;
int choose_local_over_global_scope() {
    int x = 99;
    int X = 58;
    x = -x;
    return x;
}