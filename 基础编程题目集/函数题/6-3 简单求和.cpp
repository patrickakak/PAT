int Sum (int List[], int N)
{
	int i, total = 0;

	for (i = 0; i < N; i++)
		total += List[i];
	
	return total;
}

