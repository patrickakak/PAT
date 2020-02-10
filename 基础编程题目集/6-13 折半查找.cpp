int Search_Bin(SSTable T, KeyType k) {
	int mid, low = 1, high = T.length;
	while (low <= high) {
		mid = (low + high) / 2;
		if (T.R[mid].key == k) return mid;
		else if (T.R[mid].key > k) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}
