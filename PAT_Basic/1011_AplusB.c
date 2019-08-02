/**
 * Sample Input:
 * 4
 * 1 2 3
 * 2 3 4
 * 2147483647 0 2147483646
 * 0 -2147483648 -2147483647
 * -------------------------
 * Sample Output:
 * Case #1: false
 * Case #2: true
 * Case #3: true
 * Case #4: false
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int T, i;
	long long A, B, C;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%lld%lld%lld", &A, &B, &C);
		if (A+B > C)
			printf("Case #%d: true\n", i+1);
		else
			printf("Case #%d: false\n", i+1);
	}

	return 0;
}

