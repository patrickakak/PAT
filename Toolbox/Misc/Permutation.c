#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a; *a = *b; *b = tmp;
}

/* k as the index of the last letter in string, thus 
 * k=0 means there's only one letter
 */
void permutation(char str[], int k)
{
	int i;
	
	if (k == 0)
		printf("%s\n", str);
	else
		for (i = 0; i <= k; ++i) {
			swap(&str[i], &str[k]);
			permutation(str, k-1);
			swap(&str[i], &str[k]);
		}
}

int main()
{
	char expr[100] = "abcdefg";
	int k, n;

	n = strlen(expr);
	k = n-1;
	permutation(expr, k);
	return 0;
}

