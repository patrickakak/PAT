/**
 * Sample input:
 * 630
 * -----------
 * Sample output:
 * 3
 * 5*6*7
 */
#include <cstdio>
#include <cmath>

typedef long long LL;

int main()
{
	// freopen("tst.txt", "r", stdin);
	LL n;
	scanf("%lld", &n);
	LL sqr = (LL)sqrt(1.0 * n), ansI = 0, ansLen = 0;
	for (LL i = 2; i <= sqr; i++) {
		LL tmp = 1, j = i;
		while (1) {
			tmp *= j;
			if (n % tmp != 0) break;
			if (j - i + 1 > ansLen) {
				ansI = i;
				ansLen = j - i + 1;
			}
			j++;
		}
	}
	if (ansLen == 0)
		printf("1\n%lld", n);
	else {
		printf("%lld\n", ansLen);
		for (LL i = 0; i < ansLen; i++) {
			printf("%lld", ansI + i);
			if (i < ansLen - 1)
				printf("*");
		}
	}

	return 0;
}


