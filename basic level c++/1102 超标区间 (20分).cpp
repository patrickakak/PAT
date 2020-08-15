#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, t, flag = 0, maxn = -1, cnt = 0;
	cin >> n >> t;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		maxn = max(maxn, v[i]);
		if (flag == 0 && v[i] > t) {
			printf("[%d, ", i);
			flag = 1;
			cnt++;
		}
		if (flag == 1 && (v[i]<=t || i==n-1)) {
			if (v[i] <= t) printf("%d]\n", i-1);
			else printf("%d]\n", i);
			flag = 0;
		}
	}
	if (cnt == 0) printf("%d\n", maxn);
	return 0;
}
