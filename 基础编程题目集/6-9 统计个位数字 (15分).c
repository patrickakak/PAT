int Count_Digit(const int N, const int D) {
	int tmp = N < 0 ? -N : N;
	if (N == 0 && D == 0) return 1;
	int count = 0;
	while (tmp) {
		if (tmp % 10 == D) count++;
		tmp /= 10;
	}
	return count;
}
