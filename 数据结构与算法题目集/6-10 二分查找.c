Position BinarySearch(List L, ElementType X) {
	int left = 1, mid;
	int right = L->Last;
	while (left <= right) {
		mid = (left + right)/2;
		if (X < L->Data[mid]) right = mid - 1;
		else if (X > L->Data[mid]) left = mid + 1;
		else return mid;
	}
	return NotFound;
}
