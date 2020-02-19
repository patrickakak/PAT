#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> a(400010);
int main() {
	int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	scanf("%d", &m);
	for (int j = i; j < m + i; j++) scanf("%lld", &a[j]);
	sort(a.begin(), a.begin() + m + n);
	printf("%lld\n", a[(m + n - 1) / 2]);
	return 0;
}
