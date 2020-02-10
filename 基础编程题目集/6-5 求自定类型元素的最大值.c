ElementType Max(ElementType S[], int N) {
	int MaxIndex = 0;
	for (int i = 0; i < N; i++)
		if (S[i] > S[MaxIndex]) MaxIndex = i;
	return S[MaxIndex];
}
