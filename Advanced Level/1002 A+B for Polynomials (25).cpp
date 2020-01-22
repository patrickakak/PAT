#include <iostream>
using namespace std;
int main() {
	double num, c[1001] = {0};
	int m, n, t, cnt = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%lf", &t, &num);
		c[t] += num;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%lf", &t, &num);
		c[t] += num;
	}
	for (int i = 0; i < 1001; i++)
		if (c[i] != 0) cnt++;
	printf("%d", cnt);
	for (int i = 1000; i >= 0; i--)
		if (c[i] != 0.0)
			printf(" %d %.1f", i, c[i]);
	return 0;
}
