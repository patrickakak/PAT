int Factorial(const int N) {
	if (N < 0 || N > 12)  return 0;
	int total = 1;
	for (int i = N; i > 0; i--) total *= i;
	return total;
}
