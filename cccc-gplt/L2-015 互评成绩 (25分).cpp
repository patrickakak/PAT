#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, k, m, t;
	cin >> n >> k >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int sum = 0, maxn = -1, minn = 0x2fffffff;
		for (int j = 0; j < k; j++) {
			scanf("%d", &t);
			maxn = max(maxn, t);
			minn = min(minn, t);
			sum += t;
		}
		v.push_back(sum-maxn-minn);
	}
	sort(v.rbegin(), v.rend());
	for (int i = m-1; i >= 0; i--) {
		if (i != m-1) printf(" ");
		printf("%.3f", 1.0*v[i]/(k-2));
	}
	return 0;
}
