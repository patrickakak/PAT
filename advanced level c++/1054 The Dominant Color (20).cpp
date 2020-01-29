#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int m, n, tmp;
	scanf("%d %d", &m, &n);
	unordered_map<int, int> mp;
	int half = m * n / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			mp[tmp]++;
			if (mp[tmp] > half) {
				printf("%d", tmp);
				return 0;
			}
		}
	return 0;
}
