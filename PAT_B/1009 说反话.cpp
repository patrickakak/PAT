/**
 * Sample Input:
 * Hello World Here I Come
 * -----------------------
 * Sample Output:
 * Come I Here World Hello
 */
#include <string.h>
#include <stdio.h>

#define MaxL 100
char s[MaxL];

int main()
{
	// freopen("test.txt", "r", stdin);
	int i, count;

	gets(s);
	for (count=0,i=strlen(s)-1; i >= 0; i--) {
		count++;
		if (s[i] == ' ') {
			s[i+count] = '\0';
			printf("%s ", s+i+1);
			count = 0;
		}
	}
	s[i+count+1] = '\0';
	printf("%s\n", s);

	return 0;
}

