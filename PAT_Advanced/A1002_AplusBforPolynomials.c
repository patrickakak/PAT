/**
 * Sample input:
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 * -------------
 * Sample output:
 * 3 2 1.5 1 2.9 0 3.2
 */
#include <stdio.h>

#define max_n 1001

double p[max_n] = {};

int main()
{
	// freopen("test.txt", "r", stdin);
	int k, n, i, count=0;
	double a;

	scanf("%d", &k);
	for (i = 0; i < k; i++) {
		scanf("%d %lf", &n, &a);
		p[n] += a;
	}
	scanf("%d", &k);
	for (i = 0; i< k; i++) {
		scanf("%d %lf", &n, &a);
		p[n] += a;
	}
	for (i= 0; i < max_n; i++)
		if (p[i] != 0)
			count++;

	printf("%d", count);
	for (i = max_n-1; i >= 0; i--)
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);

	return 0;
}

