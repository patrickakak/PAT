#include <iostream>
using namespace std;
int a[100000];
int main() {
	int k, tmpSum = 0, maxSum = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		tmpSum += a[i];
		if (tmpSum > maxSum) maxSum = tmpSum;
		else if (tmpSum < 0) tmpSum = 0;
	}
	printf("%d", maxSum);
	return 0;
}
