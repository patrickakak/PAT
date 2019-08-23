/**
 * Sample input1:
 * 234
 * Sample output1:
 * BBSSS1234
 * --------------
 * Sample input2:
 * 23
 * Sample output2:
 * SS123
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n/100; i++)
		printf("B");

	n -= n / 100 * 100;
	for (i = 0; i < n/10; i++)
		printf("S");

	n -= n / 10 * 10;
	for (i = 1; i <= n; i++)
		printf("%d", i);

	return 0;
}

