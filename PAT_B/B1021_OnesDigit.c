/**
 * Sample input:
 * 100311
 * Sample output:
 * 0:2
 * 1:3
 * 3:1
 */
#include <stdio.h>

#define Max_L 1024

int main()
{
	// freopen("test.txt", "r", stdin);
	char num[Max_L];
	int i = 0, count[10] = {};

	scanf("%s", num);
	while (num[i]) {
		count[num[i]-'0']++;
		i++;
	}
	for (i = 0; i < 10; i++)
		if (count[i] != 0)
			printf("%d:%d\n", i, count[i]);

	return 0;
}

