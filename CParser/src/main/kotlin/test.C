int defer_test(int x) {
	int z = addOne(x);
	if(x>0 || z>0) {
		return 1;
	}
	else {
		return 0;
	}
}