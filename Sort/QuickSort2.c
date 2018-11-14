/* Quick sort */

ElementType Median3(ElementType A[], int Left, int Right)
{ 
	int Center = (Left+Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap( &A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap( &A[Center], &A[Right]);
	/* A[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right-1]);	/* Hide Pivot into A[Right-1] */
	/* Only need to consider A[Left+1] ... A[Right-2] */
	return A[Right-1];	/* Return Pivot */
}

/* The core recusive quick sort function */
void Qsort(ElementType A[], int Left, int Right)
{
	int Pivot, Cutoff, Low, High;

	if (Cutoff <= Right-Left) {		/* If elements in sequence is quite enough, use quick sort */
		Pivot = Median3(A, Left, Right);	/* Pick a pivot */ 
		Low = Left;
		High = Right-1;
		while (1) {		/* Move elements less than pivot to left part, others right part */
			while (A[++Low] < Pivot) ;
			while (A[--High] > Pivot) ;
			if (Low < High) Swap(&A[Low], &A[High]);
			else break;
		}
		Swap(&A[Low], &A[Right-1]);		/* Place pivot into the right place */ 
		Qsort(A, Left, Low-1);	/* Handle the left part recursively */ 
		Qsort(A, Low+1, Right);		/* Get the right part done recursively */  
	} else
		InsertionSort(A+Left, Right-Left+1);	/* Insufficient elements, using simple sort instead */ 
}

/* Unified interface */
void QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N-1);
}

