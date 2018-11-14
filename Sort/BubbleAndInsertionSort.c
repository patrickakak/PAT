void BubbleSort(ElementType A[], int N)
{
	int P, i, flag;

	for (P = N-1; P >= 0; P--) {
		flag = 0;
		for (i = 0; i < P; i++)		/* One single bubble sort */
			if (A[i] > A[i+1]) {
				Swap(A[i], A[i+1]);
				flag = 1;	/* To indicate a exchange */
			}
		if (flag == 0) break;	/* There's no exchange */
	}
}

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

