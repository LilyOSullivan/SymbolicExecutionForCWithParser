// Ensure expressions can be treated as true/false
// This tests the not-equality (!=) operator

int bad_return_not_equal(int x) {
    return 1+(2!=5);
}