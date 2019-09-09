/**
 * Sample input:
 * helloworld!
 * ------------
 * Sample output:
 * h   !
 * e   d
 * l   l
 * lowor
 */
#include <stdio.h>
#include <string.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	char s[100];
	int n1, n2, len, i, j, k;

	scanf("%s", s);
	len = strlen(s);
	n1 = len / 2;
	n2 = len - 2*n1 + 2;
	while (n1 > n2) {
		n1--;
		n2 += 2;
	}
	for (i=0, j=len-1; i < n1-1; i++, j--) {
		printf("%c", s[i]);
		for (k = 0; k < n2-2; k++)
			printf(" ");
		printf("%c\n", s[j]);
	}
	for (; i <= j; i++)
		printf("%c", s[i]);

	return 0;
}

