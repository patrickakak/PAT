/* Merge sort - loop method */

/* length = the length of the current ordered sub-sequence 
 *
 * Merge the adjacent two sub-sequences
 */
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i, j;

	for (i=0; i <= N-2*length; i += 2*length)
		Merge(A, TmpA, i, i+length, i+2*length-1);
	if (i+length < N)	/* Merge the last 2 sub-sequences */
		Merge(A, TmpA, i, i+length, N-1);
	else	/* There's only 1 sub-sequence left */
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{ 
	int length; 
	ElementType *TmpA;

	length = 1;		/* Initialize the length of sub-sequence */
	TmpA = (ElementType *) malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	} else
		printf("No enough space!\n");
}

