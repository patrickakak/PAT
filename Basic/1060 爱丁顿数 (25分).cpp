#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int e = 0, p = 1;
	while (e <= n && a[p] > p) {
		e++;
		p++;
	}
	cout << e;
	return 0;
}
