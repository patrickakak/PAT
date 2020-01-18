int binSearch(SeqList T, KeyType k)
{
	int index = 0;
	int mid, low = 1, high = T.len;

	while (low <= high) {
		mid = (low + high)/2;

		if (T.data[mid].key == k) {
			index = mid;
			return index;
		} else if (T.data[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return index;
}

