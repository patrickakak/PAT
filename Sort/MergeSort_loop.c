/**
 * Merge sort (stable):
 * Worst: Tw = O(NlogN), usually be used as a way of external sort
 */

/* Don't need to copy ordered sequence from TmpA[] to A[] */
void Merge1(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, Tmp;

	LeftEnd = R - 1;	/* The end position of left part */
	Tmp = L;	/* The starting position of ordered sequence */

	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];	/* Copy elements in left part into TmpA */
		else
			TmpA[Tmp++] = A[R++];	/* Copy elements in right part into TmpA */

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];	/* Copy the leftover of left part */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];	/* Copy the leftover of right part */
}

/**
 * function: merge the adjacent two subsequences
 * length: equals to the length of the current ordered subsequence 
 */
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i, j;

	/**
	 * When parameter length is an odd number, the last pair may be in 
	 * different size, 'i<=N-2*length' means to merge until we meet the last 
	 * but tow subsequence, then merge the tail pair
	 */ 
	for (i = 0; i <= N-2*length; i += 2*length)
		Merge1(A, TmpA, i, i+length, i+2*length-1);

	if (i+length < N)	/* Merge the last 2 sub-sequences */
		Merge1(A, TmpA, i, i+length, N-1);
	else	/* There's only 1 sub-sequence left */
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

/* Unified interface */
void Merge_Sort(ElementType A[], int N)
{ 
	int length; 
	ElementType *TmpA;

	length = 1;		/* Initialize the length of subsequence */
	TmpA = (ElementType *) malloc(N * sizeof(ElementType));

	if (TmpA == NULL)
		printf("No enough space!\n");
	else {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
}

