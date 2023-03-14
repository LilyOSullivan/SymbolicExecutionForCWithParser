// Ensure expressions can be treated as true/false 
// This tests the less-than or equal-to operator

int bad_return_lt_equal(int x) {
    return 1+(2<=5);
}