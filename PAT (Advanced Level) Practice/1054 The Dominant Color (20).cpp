#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int m, n, t;
	scanf("%d %d", &m, &n);
	unordered_map<int, int> mp;
	int half = m * n / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			mp[t]++;
			if (mp[t] > half) {
				printf("%d", t);
				return 0;
			}
		}
	return 0;
}
