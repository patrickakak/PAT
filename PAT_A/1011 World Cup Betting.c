/**
 * Sample input:
 * 1.1 2.5 1.7
 * 1.2 3.1 1.6
 * 4.1 1.2 1.1
 * -------------
 * Sample output:
 * T T W 39.31
 */
#include <stdio.h>

int max(double W, double T, double L)
{
	if (W > T)
		return W > L ? 0 : 2;
	else
		return T > L ? 1 : 2;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	double W, T, L, r[3] = {};
	char chs[3] = {};
	int i, ret;

	for (i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &W, &T, &L);
		ret = max(W, T, L);
		switch (ret) {
		case 0:
			r[i] = W;
			chs[i] = 'W';
			break;
		case 1:
			r[i] = T;
			chs[i] = 'T';
			break;
		case 2:
			r[i] = L;
			chs[i] = 'L';
			break;
		}
	}
	for (i = 0; i < 3; i++)
		printf("%c ", chs[i]);
	printf("%.2f\n", (r[0]*r[1]*r[2]*0.65-1)*2);

	return 0;
}

