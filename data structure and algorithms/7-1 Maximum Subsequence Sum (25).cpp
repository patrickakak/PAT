#include <iostream>
using namespace std;
int a[100000];
int main() {
	int k, tmpSum = 0, maxSum = -1, first, last, tmp = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		tmpSum += a[i];
		if (tmpSum > maxSum) {
			maxSum = tmpSum;
			last = i;
		} else if (tmpSum < 0)
			tmpSum = 0;
	}
	for (int i = last; i >= 0; i--) {
		tmp += a[i];
		if (tmp == maxSum) first = i;
	}
	if (maxSum == -1) printf("0 %d %d", a[0], a[k-1]);
	else printf("%d %d %d", maxSum, a[first], a[last]);
	return 0;
}
