/**
 * Sample Input:
 * 123 456 8
 * ------------
 * Sample Output:
 * 1103
 */
#include <stdio.h>

int arr[32] = {0};

int main()
{
	int A, B, D;
	int i, sum;

	// freopen("test.txt", "r", stdin);
	scanf("%d%d%d", &A, &B, &D);

	i = 0;
	sum = A + B;
	do {
		arr[i] = sum % D;
		i++;
		sum /= D;
	} while (sum != 0);

	i--;
	for (; i >= 0; i--)
		printf("%d", arr[i]);

	return 0;
}

