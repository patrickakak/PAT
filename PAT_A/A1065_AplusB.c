/**
 * Sample Input:
 * 3
 * 1 2 3
 * 2 3 4
 * 9223372036854775807 -9223372036854775808 0
 * -----------------
 * Sample Output:
 * Case #1: false
 * Case #2: true
 * Case #3: false
 */
#include <stdio.h>
#include <stdbool.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int T, count = 1;
	long long A, B, C, res;
	bool flag;

	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &A, &B, &C);
		res = A + B;
		if (A > 0 && B > 0 && res < 0)
			flag = true;
		else if (A < 0 && B < 0 && res >= 0)
			flag = false;
		else if (res > C)
			flag = true;
		else
			flag = false;

		if (flag)
			printf("Case #%d: true\n", count++);
		else
			printf("Case #%d: false\n", count++);
	}
	return 0;
}


