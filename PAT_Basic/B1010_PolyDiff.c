/**
 * Sample Input:
 * 3 4 -5 2 6 1 -2 0
 * Sample Output:
 * 12 3 -10 1 6 0
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int A, B, flag = 1, count = 0;

	while (scanf("%d%d", &A, &B) != EOF) {
		count++;
		if (B == 0) {
			if (count == 1)
				printf("0 0");
			break;
		} else {
			if (flag) {
				printf("%d %d", A*B, B-1);
				flag = 0;
			} else
				printf(" %d %d", A*B, B-1);
		}
	}

	return 0;
}


