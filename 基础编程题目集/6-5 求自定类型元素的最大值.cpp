ElementType Max(ElementType S[], int N)
{
	int i, MaxIndex = 0;
	
	for (i = 0; i < N; i++)
		if (S[i] > S[MaxIndex])
			MaxIndex = i;
			
	return S[MaxIndex];
}

