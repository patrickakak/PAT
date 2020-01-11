/**
 * Sample input:
 * 19 *
 * -----------
 * Sample output:
 * *****
 *  ***
 *   *
 *  ***
 * *****
 * 2
 */
#include <cstdio>
#include <cmath>

int main()
{
	// freopen("tst.txt", "r", stdin);
	char c;
	int n, bottom, used;

	scanf("%d %c", &n, &c);
	bottom = (int)sqrt(2.0 * (n + 1)) - 1;
	if (bottom % 2 == 0)
		bottom--;
	used = (bottom + 1)*(bottom + 1)/2 - 1;
	for (int i = bottom; i >= 1; i -= 2) {
		for (int j = 0; j < (bottom-i)/2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	for (int i = 3; i <= bottom; i += 2) {
		for (int j = 0; j < (bottom-i)/2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d\n", n-used);

	return 0;
}


