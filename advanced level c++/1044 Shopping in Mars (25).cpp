#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, tmp, minn = 0x2fffffff;
	cin >> n >> m;
	vector<int> sum(n+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		sum[i] = sum[i-1] + tmp;
	}
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(sum.begin()+i, sum.end(), sum[i-1]+m) - sum.begin();
		if (p <= n && minn > sum[p]-sum[i-1]) minn = sum[p] - sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(sum.begin()+i, sum.end(), sum[i-1]+m) - sum.begin();
		if (p <= n && minn == sum[p]-sum[i-1]) printf("%d-%d\n", i, p);
	}
	return 0;
}
