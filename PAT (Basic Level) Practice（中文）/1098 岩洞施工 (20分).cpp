#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, minn = 0x2fffffff, maxn = -1;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		minn = min(minn, a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		maxn = max(maxn, b[i]);
	}
	if (minn > maxn) printf("Yes %d", minn - maxn);
	else printf("No %d", maxn - minn + 1);
	return 0;
}
