// Ensure expressions can be treated as true/false 
// This tests the greater-than or equal-to (<=) operator

int bad_return_gt_equal(int x) {
    return 1+(2>=5);
}