/**
 * Sample Input:
 * 10 a
 * --------------
 * Sample Output:
 * aaaaaaaaaa
 * a        a
 * a        a
 * a        a
 * aaaaaaaaaa
 */
#include <stdio.h>

int main()
{
	int N, row, i, j;
	char ch;

	// freopen("test.txt", "r", stdin);
	scanf("%d %c", &N, &ch);

	row = (N%2 == 1 ? N/2+1 : N/2);
	for (i = 0; i < row; i++) {
		for (j = 0; j < N; j++)
			if (i == 0 || i == row-1)
				printf("%c", ch);
			else {
				if (j == 0 || j == N-1)
					printf("%c", ch);
				else
					printf(" ");
			}
		printf("\n");
	}
	return 0;
}


