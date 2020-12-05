#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void downAdjust(vector<int> &v, int low, int high) {
	int i = 1, j = i * 2;
	while (j <= high) {
		if (j+1 <= high && v[j] < v[j+1]) j++;
		if (v[i] >= v[j]) break;
		swap(v[i], v[j]);
		i = j, j = i * 2;
	}
}
int main() {
	int n, i = 2;
	scanf("%d", &n);
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (; i <= n && b[i-1] <= b[i]; i++) ;
	int j = i;
	for (; j <= n && a[j] == b[j]; j++) ;
	if (j == n+1) {
		printf("Insertion Sort\n");
		sort(b.begin()+1, b.begin()+i+1);
	} else {
		printf("Heap Sort\n");
		int p = n;
		while (p > 2 && b[p] >= b[1]) p--;
		swap(b[1], b[p]);
		downAdjust(b, 1, p-1);
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) printf(" ");
		printf("%d", b[i]);
	}
	return 0;
}
