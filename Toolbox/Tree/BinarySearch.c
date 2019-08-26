#define NotFound -1

typedef struct Node *List;
struct Node {
	ElementType Data[MaxSize];
	int Length;
};

/* Depth of binary tree: [lgN]+1 */
int BinarySearch(List Tbl, ElementType K)
{
	int left, right, mid;

	left = 1; 	/* Initialize left boundary */
	right = Tbl->Length; 	/* Right boundary */
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

