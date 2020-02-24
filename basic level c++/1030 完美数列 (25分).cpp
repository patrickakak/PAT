#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, p, len = 0;
	cin >> n >> p;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i + len < n; i++) {
		int j;
		for (j = i + len; j < n; j++)
			if (v[j] > p * v[i]) break;
		if (j - i > len) len = j - i;
	}
	printf("%d", len);
	return 0;
}
