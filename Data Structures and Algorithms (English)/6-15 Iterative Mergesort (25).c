void Merge1(ElementType A[], ElementType sorted[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1, Tmp = L;
	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R]) sorted[Tmp++] = A[L++];
		else sorted[Tmp++] = A[R++];
	while (L <= LeftEnd) sorted[Tmp++] = A[L++];
	while (R <= RightEnd) sorted[Tmp++] = A[R++];
}
void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
	int i;
	for (i = 0; i <= N-2*length; i += 2*length)
		Merge1(list, sorted, i, i+length, i+2*length-1);
	if (i + length < N) Merge1(list, sorted, i, i+length, N-1);
	else for (int j = i; j < N; j++) sorted[j] = list[j];
}
