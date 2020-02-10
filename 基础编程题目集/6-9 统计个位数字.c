int Count_Digit(const int N, const int D) {
	int temp, count;
	temp = N < 0 ? -N : N;
	if (N == 0 && D == 0)  return 1;
	count = 0;
	while (temp) {
		if (temp%10 == D) count++;
		temp /= 10;
	}
	return count;
}
