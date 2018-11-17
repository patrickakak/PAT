/**
 * Insertioin sort:
 * */
void InsertionSort(ElementType A[], int N)
{
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P];		/* Get the first element of the unsorted */
		for (i = P; i>0 && A[i-1]>Tmp; i--)
			A[i] = A[i-1];	/* Right shift */
		A[i] = Tmp;		/* Put it in the right place */
	}
}

