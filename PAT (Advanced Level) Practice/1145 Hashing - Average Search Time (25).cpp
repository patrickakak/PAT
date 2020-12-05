#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int sz, n, m, key, ans = 0;
	scanf("%d %d %d", &sz, &n, &m);
	while (!isprime(sz)) sz++;
	vector<int> v(sz);
	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		int flag = 0;
		for (int step = 0; step <= sz; step++) {
			int pos = (key + step * step) % sz;
			if (v[pos] == 0) {
				v[pos] = key;
				flag = 1;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n", key);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &key);
		for (int step = 0; step <= sz; step++) {
			ans++;
			int pos = (key + step * step) % sz;
			if (v[pos] == key || v[pos] == 0) break;
		}
	}
	printf("%.1lf\n", 1.0 * ans / m);
	return 0;
}
