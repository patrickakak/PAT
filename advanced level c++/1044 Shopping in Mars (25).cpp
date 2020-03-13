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
		int p = lower_bound(sum.begin()+i, sum.end(), sum[i-1]+m) - (sum.begin()+i);
		if (i+p <= n && minn > sum[i+p]-sum[i-1]) minn = sum[i+p]-sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(sum.begin()+i, sum.end(), sum[i-1]+m)-(sum.begin()+i);
		if (p <= n && sum[i+p]-sum[i-1] == minn) printf("%d-%d\n", i, i+p);
	}
	return 0;
}
