int Factorial(const int N)
{
	if (N < 0 || N > 12)  return 0;
	
	int i, total = 1;
	for (i = N; i > 0; i--)
		total *= i;
		
	return total;
}

