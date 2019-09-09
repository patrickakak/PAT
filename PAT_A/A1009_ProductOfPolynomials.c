/**
 * Sample input:
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 * --------------
 * Sample output:
 * 3 3 3.6 2 6.0 1 1.6
 */
#include <stdio.h>

#define MaxL 2000	// x^1000 * x^1000
double P1[MaxL+1], P2[MaxL+1];

int main()
{
	// freopen("test.txt", "r", stdin);
	int K1, K2, i, j, e, count=0;
	double c;

	scanf("%d", &K1);
	for (i = 0; i < K1; i++) {
		scanf("%d %lf", &e, &c);
		P1[e] = c;
	}
	scanf("%d", &K2);
	for (i = 0; i < K2; i++) {
		scanf("%d %lf", &e, &c);
		for (j = 0; j < MaxL; j++)
			P2[e+j] += c * P1[j];
	}

	for (i = MaxL; i >= 0; i--)
		if (P2[i] != 0)
			count++;
	printf("%d", count);
	for (i = MaxL; i >= 0; i--)
		if (P2[i] != 0)
			printf(" %d %.1f", i, P2[i]);

	return 0;
}

