/* Shell sort using Sedgewick increment sequence */
void ShellSort(ElementType A[], int N)
{
	int Si, D, P, i;
	ElementType Tmp;
	/* Only a small part of the increments */
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	/* The initial increment(i.e. Sedgewick[Si]) can't exceed the lenght of 
	 * the unsorted sequence */
	for (Si = 0; Sedgewick[Si] >= N; Si++) ;

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) {	/* Insertion sort */
			Tmp = A[P];
			for (i = P; i >= 0 && A[i-D] > Tmp; i -= D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
}

