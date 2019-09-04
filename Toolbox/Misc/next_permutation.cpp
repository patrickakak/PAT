#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a; *a = *b; *b = tmp;
}

/* n as the number of characters in string, thus
 * n=1 means this time, one perticular permutation is done
 *
 * A problem of length n, swap the first and the last char,
 * then it becomes a problem of length n-1, don't forget to
 * swap back later
 */
void permutation(char s[], int n)
{
	int i;

	if (n == 1)
		printf("%s\n", s);
	else
		for (i = 0; i < n; ++i) {
			swap(&s[i], &s[n-1]);
			permutation(s, n-1);
			swap(&s[i], &s[n-1]);
		}
}

int main()
{
	char s[100] = "abc";
	int len = strlen(s);

	/* Version1: Made by user */
	// permutation(s, len);

	/* Version2: STL */
	do {
		for (int i = 0; i < len; i++)
			printf("%c", s[i]);
		printf("\n");
	} while (next_permutation(s, s+len));

	return 0;
}

