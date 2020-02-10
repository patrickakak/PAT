int IsTheNumber(const int N) {
	int yes = 0, tmp = N, arr[10] = {0};
	while (tmp) {
		arr[tmp % 10]++;
		tmp /= 10;
	}
	for (int i = 0; i < 10; i++)
		if (arr[i] > 1 && sqrt(N) == (int)sqrt(N)) {
			yes = 1;
			break;
		}
	return yes;
}
