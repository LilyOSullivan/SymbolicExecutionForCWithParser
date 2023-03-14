// Ensure expressions can be treated as true/false 
// This tests the equality (==) operator

int bad_return_equal(int x) {
    return 1+(2==5);
}