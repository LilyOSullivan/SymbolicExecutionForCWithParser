// Ensure expressions can be treated as true/false 
// This tests the greater-than (>) operator

int bad_return_gt(int x) {
    return 1+(2>5);
}