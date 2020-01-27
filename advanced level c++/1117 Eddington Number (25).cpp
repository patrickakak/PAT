#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend()-1);
	int e = 0, p = 1;
	while (e <= n && a[p] > p) {
		e++;
		p++;
	}
	cout << e;
	return 0;
}
