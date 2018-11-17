/**
 * Merge sort (stable): 
 * Worst: Tw = O(NlogN)
 *
 * Recursive version: L equals to the starting index of left part, R equals to 
 * the starting index of right part, RightEnd = the end index of the left part
 *
 * Merge Sort well-ordered A[L]~A[R-1] and A[R]~A[RightEnd] out into 
 * an ordered sequence
 */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1;	/* The end position of left part */
	Tmp = L;	/* The starting position of ordered sequence */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];	/* Copy elements in left part into TmpA */
		else
			TmpA[Tmp++] = A[R++];	/* Copy elements in right part into TmpA */
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];	/* Copy the leftover of left part */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];	/* Copy the leftover of right part */

	/* Copy ordered sequence from TmpA[] to A[] */
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

/* The core merge sort function */
void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;

	if (L < RightEnd) {
		Center = (L+RightEnd) / 2;
		Msort(A, TmpA, L, Center);	/* Handle the left part recursively */ 
		Msort(A, TmpA, Center+1, RightEnd);		/* Handle the right part */
		Merge(A, TmpA, L, Center+1, RightEnd);	/* Merge two sequences */ 
	}
}

/* Unified interface */
void MergeSort(ElementType A[], int N)
{
	ElementType *TmpA;
	TmpA = (ElementType *) malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N-1);
		free(TmpA);
	} else
		printf("Not enough space!\n");
}

