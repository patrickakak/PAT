#include <iostream>
using namespace std;
int h[1010];
int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		h[t]++;
	}
	for (int i = 1; i <= m/2; i++) {
		if (i == m-i && h[i] >= 2) {
			printf("%d %d", i, m-i);
			return 0;
		}
		if (i != m-i && h[i] >= 1 && h[m-i] >= 1) {
			printf("%d %d", i, m-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
