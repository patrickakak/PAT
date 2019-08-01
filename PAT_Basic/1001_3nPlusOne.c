/**
 * Sample Input:
 * 3
 * Sample Output:
 * 5
 */
#include <stdio.h>

int main()
{
	int n, count;

	scanf("%d", &n);

	count = 0;
	while (n != 1) {
		if (n % 2 == 1)
			n = (3*n + 1)/2;
		else
			n/=2;
		count++;
	}
	printf("%d\n", count);

	return 0;
}


