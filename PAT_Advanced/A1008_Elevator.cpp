/**
 * Sample input:
 * 3 2 3 1
 * -------------
 * Sample output:
 * 41
 */
#include <cstdio>

#define maxn 100010
int a[maxn], sum = 0;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	a[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int diff = a[i] - a[i-1];
		if (diff > 0)
			sum += diff * 6 + 5;
		else if (diff < 0)
			sum += (-diff) * 4 + 5;
		else
			sum += 5;
	}
	printf("%d\n", sum);

	return 0;
}


