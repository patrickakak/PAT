/**
 * Binary insertion sort: T=O(n^2)
 *
 * improve insertion sort by finding the position to insert more effeciently
 */

int findPlace(int A[], int tmp, int high)
{
	int mid, low = 0;

	while (low <= high) {
		mid = (low + high)/2;
		if (tmp >= A[mid])	/* Add '=' in order to move less elements */
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high+1;
}

void BinaryInsertionSort(int A[], int n)
{
	int i, j;
	int tmp, high, p;

	for (high=0, i=1; i < n; i++) {
		tmp = A[i];
		p = findPlace(A, tmp, high);
		for (j = high; j >= p; j--)
			A[j+1] = A[j];
		A[p] = tmp;
		high += 1;
	}
}

