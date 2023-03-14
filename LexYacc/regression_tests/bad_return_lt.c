// Ensure expressions can be treated as true/false 
// This tests the less-than (<) operator

int bad_return_lt(int x) {
    return 1+(2<5);
}