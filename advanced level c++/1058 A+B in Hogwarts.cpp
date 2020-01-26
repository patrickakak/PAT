/**
 * Sample input:
 * 3.2.1 10.16.27
 * --------------
 * Sample output:
 * 14.1.28
 */
#include <stdio.h>

#define G2S 17
#define S2K 29

typedef struct {
	long long G, S, K;
} currency;

int main()
{
	// freopen("test.txt", "r", stdin);
	currency A, B, C;
	long long a, b, c;

	scanf("%lld.%lld.%lld %lld.%lld.%lld", &A.G, &A.S, &A.K, &B.G, &B.S, &B.K);

	a = A.G*G2S*S2K + A.S*S2K + A.K;
	b = B.G*G2S*S2K + B.S*S2K + B.K;
	c = a + b;
	C.G = c / S2K / G2S;
	c -= C.G*G2S*S2K;
	C.S = c / S2K;
	c -= C.S*S2K;
	C.K = c;
	printf("%lld.%lld.%lld\n", C.G, C.S, C.K);

	return 0;
}

