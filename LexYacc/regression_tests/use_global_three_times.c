// Call a function that re-uses a global

int x=1;

int inc() {
    x += 1;
    return x;
}

int use_global_three_times(int x) {
    return inc() + inc() + inc();
}