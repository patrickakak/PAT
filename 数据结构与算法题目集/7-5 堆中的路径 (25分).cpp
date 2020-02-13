#include <iostream>
using namespace std;
int main() {
	int n, m, t, h[1010];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		h[i] = t;
		int j = i;
		while (j > 1)
			if (h[j/2] > t) {
				h[j] = h[j/2];
				j /= 2;
			} else break;
		h[j] = t;
	}
	while (m--) {
		scanf("%d", &t);
		for (int j = t; j >= 1; j /= 2) {
			if (j != t) printf(" ");
			printf("%d", h[j]);
		}
		printf("\n");
	}
	return 0;
}
