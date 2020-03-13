#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, a[100], b[100], i, j;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++) ;
	for (j = i + 1; a[j] == b[j] && j < n; j++) ;
	if (j == n) {
		printf("Insertion Sort\n");
		sort(a, a + i + 2);
	} else {
		printf("Merge Sort\n");
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (int i = 0; i < n; i++)
				if (a[i] != b[i]) {
					flag = 1;
					break;
				}
			k *= 2;
			for (int i = 0; i < n / k; i++)
				sort(a + i * k, a + (i + 1) * k);
			sort(a + n / k * k, a + n);
		}
	}
	for (int j = 0; j < n; j++) {
		if (j != 0) printf(" ");
		printf("%d", a[j]);
	}
	return 0;
}
