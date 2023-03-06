// Recursive function calls

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int fib_helper(int x) {
    if(x == 9) {
        return fib(5) + fib(7);
    }
    return 0;
}