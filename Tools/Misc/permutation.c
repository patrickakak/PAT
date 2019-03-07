#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a; *a = *b; *b = tmp;
}

void permutation(char str[], int k, int n)
{
	int i, j;

	if (k == 0) {
		for (j = 0; j < n; ++j)
			printf("%c", str[j]);
		printf("\n");
	} else
		for (i = 0; i <= k; ++i) {
			swap(&str[i], &str[k]);
			permutation(str, k-1, n);
			swap(&str[i], &str[k]);
		}
}

int main()
{
	char expr[100] = "abcdefg";
	int k, n;

	n = strlen(expr);
	k = n-1;
	permutation(expr, k, n);
	return 0;
}

