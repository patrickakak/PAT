#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a; *a = *b; *b = tmp;
}

/* k as the index of the last letter in string, thus 
 * k=0 means this time, one perticular permutation is done
 * 
 * A problem of length n, swap the first and the last char,
 * then it becomes a problem of length n-1, don't forget to
 * swap the two back later
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
	int k;

	k = strlen(expr);
	permutation(expr, k-1);
	return 0;
}

