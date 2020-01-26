#include <iostream>
#include <map>
using namespace std;
int main() {
	int m, n, tmp;
	scanf("%d %d", &m, &n);
	map<int, int> a;
	int half = m * n / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			a[tmp]++;
			if (a[tmp] > half) {
				printf("%d", tmp);
				return 0;
			}
		}
	return 0;
}
