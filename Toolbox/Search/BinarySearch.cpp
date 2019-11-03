/**
 * Binary Search: T = O(logN)
 */
#define NotFound -1

typedef struct Node *List;
struct Node {
	ElementType Data[MaxSize];
	int Length;
};

/* Depth of binary tree: [lgN]+1, (Strictly increasing) */
int BinarySearch(List Tbl, ElementType K)
{
	int left, right, mid;

	left = 1; 	/* Initialize left boundary */
	right = Tbl->Length; 	/* Right boundary */
	// Search in [left, right)
	while (left <= right) {
		// mid = (left + right)/2;
		mid = left + (right-left)/2; 	// To avoid overflow
		/* If we update rignt and left pointer to mid only, then it may stuck 
		 * into a dead loop: (e.g. left=1, right=2 and K!=Tbl->Data[1]) */
		if (K < Tbl->Data[mid])
			right = mid - 1;
		else if (K > Tbl->Data[mid])
			left = mid + 1;
		else
			return mid; 	/* Find the K */
	}
	return NotFound; 	/* Searching failed */
}

/* Not strictly increasing (i.e. non-descending)
 * the inicial left and right should be 0 and n respectively */
int lower_bound(int A[], int left, int right, int x)
{
	int mid;
	// Search in [left, right]
	while (left < right) {	// "left=right" to quit
		mid = left + (right-left)/2;
		if (A[mid] >= x)
			right = mid;	// then in [left, mid]
		else
			left = mid + 1;
	}
	return left;	// Can also be "return right"
}

/* Same as lower_bound() */
int upper_bound(int A[], int left, int right, int x)
{
	int mid;
	// Search in [left, right]
	while (left < right) {
		mid = left + (right-left)/2;
		if (A[mid] > x)		// diff from lower_bound
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

/* Template of solving the problem of finding 1st element which satisfies 
 * a given condition in a ordered sequence */
int solve(int left, int right)
{
	int mid;
	// Search in [left, right]
	while (left < right) {
		mid = left + (right-left)/2;
		if (Condition satisfied)	// or !Condition
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}


