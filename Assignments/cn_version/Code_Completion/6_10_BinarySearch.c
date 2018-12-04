/**
 * Sample input #1:
 * 5
 * 12 31 55 89 101
 * 31
 * Sample output #1:
 * 2
 * -----------------
 * Sample input #2:
 * 3
 * 26 78 233
 * 31
 * Sample output #2:
 * 0
 */
/* A list contains a bunch of ordered elements */
Position BinarySearch(List L, ElementType X)
{
	int left, right, mid;

	left = 1;
	right = L->Last;
	while (left <= right) {
		mid = (left + right)/2;
		if (X < L->Data[mid])
			right = mid - 1;
		else if (X > L->Data[mid])
			left = mid + 1;
		else
			return mid;
	}
	return NotFound;
}

