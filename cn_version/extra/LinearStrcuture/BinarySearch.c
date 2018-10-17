#define NotFound -1

typedef struct Node *List;
struct Node {
	ElementType Data[MaxSize];
	int Length;
};

/* Depth of binary tree: [log2N]+1 */
int BinarySearch(List Tbl, ElementType K)
{
	int left, right, mid;

	left = 1; 	/* Initialize left boundary */
	right = Tbl->Length; 	/* Right boundary */
	while (left <= right) {
		mid = (left + right)/2;
		if (K < Tbl->Data[mid])
			right = mid - 1;
		else if (K > Tbl->Data[mid])
			left = mid + 1;
		else
			return mid; 	/* Find the K */
	}
	return NotFound; 	/* Searching failed */
}

