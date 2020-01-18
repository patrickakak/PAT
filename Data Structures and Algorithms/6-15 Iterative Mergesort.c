/**
 * 6-15: Implement mergesort without using recursion.
 * (The idea of iterative mergesort is to start from N sorted sublists 
 * of length 1, and each time to merge a pair of adjacent sublists 
 * until one sorted list is obtained. You are supposed to implement 
 * the key function of merging.)
 * -------------------------------------------------------------------
 * Sample Input:
 * 10
 * 8 7 9 2 3 5 1 6 4 0
 * -------------------
 * Sample Output:
 * 7 8 2 9 3 5 1 6 0 4 
 * 2 7 8 9 1 3 5 6 0 4 
 * 1 2 3 5 6 7 8 9 0 4 
 * 0 1 2 3 4 5 6 7 8 9 
 * 0 1 2 3 4 5 6 7 8 9 
 */
void Merge1(ElementType A[], ElementType sorted[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;

	LeftEnd = R - 1;
	Tmp = L;

	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R])
			sorted[Tmp++] = A[L++];
		else
			sorted[Tmp++] = A[R++];

	while (L <= LeftEnd)
		sorted[Tmp++] = A[L++];
	while (R <= RightEnd)
		sorted[Tmp++] = A[R++];
}

void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
	int i, j;

	for (i = 0; i <= N-2*length; i += 2*length)
		Merge1(list, sorted, i, i+length, i+2*length-1);

	if (i+length < N)
		Merge1(list, sorted, i, i+length, N-1);
	else
		for (j = i; j < N; j++) sorted[j] = list[j];
}

