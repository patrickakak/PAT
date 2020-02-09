#include <cstdio>
int main() {
	int a, cnt=0;
	scanf("%d", &a);
	for (int i = a; i < a + 4; i++)
		for (int j = a; j < a + 4; j++) {
			if (j == i) continue;
			for (int k = a; k < a + 4; k++) {
				if (k == i || k == j) continue;
				printf("%d%d%d", i, j, k);
				cnt++;
				if (cnt % 6 == 0) printf("\n");
				else printf(" ");
			}
		}
	return 0;
}
