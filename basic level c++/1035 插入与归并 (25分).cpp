#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, i, j, k = 1, flag = 0;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (i = 1; i < n && b[i-1] <= b[i]; i++) ;
	for (j = i; j < n && a[j] == b[j]; j++) ;
	if (j == n) {
		printf("Insertion Sort\n");
		sort(a.begin(), a.begin() + i + 1);
	} else {
		printf("Merge Sort\n");
		while (1) {
			for (i = 0; i < n && a[i] == b[i]; i++) ;
			if (i == n) flag = 1;
			k *= 2;
			for (int j = 0; j < n; j += k)
				sort(a.begin() + j, a.begin() + min(n, j+k));
			if (flag == 1) break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", a[i]);
	}
	return 0;
}
