int binSearch(SeqList T, KeyType k) {
	int mid, low = 1, high = T.len;
	while (low <= high) {
		mid = (low + high) / 2;
		if (T.data[mid].key == k) return mid;
		else if (T.data[mid].key > k) high = mid - 1;
		else low = mid + 1;
	}
	return index;
}
