/**
 * Selection sort:
 * Worst: Tw = O(N^2) when using simple traverse search
 * extra S = O(1)
 * can be optimised by using minheap technique(Tw=N*logN)
 */
void SelectionSort(ElementType A[], int N)
{
	int i, MinPosition;

	for (i = 0; i < N; i++) {
		/* Find the index of minimum element between A[i] and A[N-1] 
		 * (which is a unsorted set) */
		MinPosition = ScanForMin(A, i, N-1);
		/* Add the element to the rear of sorted set */
		Swap(A[i], A[MinPosition]);
	}
}

