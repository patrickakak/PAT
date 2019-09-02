/**
 * Sample input:
 * 4
 * 0.1 0.2 0.3 0.4
 * ----------------
 * Sample output:
 * 5.00
 */
#include <cstdio>

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	double v, ans = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &v);
		ans += v * i * (n + 1 - i);
	}
	printf("%.2f\n", ans);

	return 0;
}


