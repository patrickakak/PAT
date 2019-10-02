/**
 * Sample Input1:
 * 3862767 6 13530293 3
 * Sample Output1:
 * 399
 * --------------------
 * Sample Input2:
 * 3862767 1 13530293 8
 * Sample Output2:
 * 0
 */
#include <stdio.h>

int getP(int A, int Da)
{
	int ret = 0;
	do {
		if (A % 10 == Da) {
			ret *= 10;
			ret += Da;
		}
		A /= 10;
	} while (A);
	return ret;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	int A, Da, B, Db, Pa, Pb;

	scanf("%d%d%d%d", &A, &Da, &B, &Db);
	Pa = getP(A, Da);
	Pb = getP(B, Db);
	printf("%d\n", Pa+Pb);

	return 0;
}

