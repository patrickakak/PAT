/**
 * Sample input:
 * 12345
 * ------------
 * Sample output:
 * one five
 */
#include <stdio.h>

// Number to words
char N2W[10][10]= {"zero", "one", "two", "three", "four", 
                   "five", "six", "seven", "eight", "nine"};

int main()
{
	// freopen("test.txt", "r", stdin);
	char num[105];
	int sum, i, r, stack[105], top=-1;

	scanf("%s", num);
	i = 0; sum = 0;
	while (num[i]) {
		sum += num[i] - '0';
		i++;
	}

	do {
		r = sum % 10;
		stack[++top] = r;
		sum /= 10;
	} while (sum);

	while (top!=0)
		printf("%s ", N2W[stack[top--]]);
	printf("%s", N2W[stack[top]]);

	return 0;
}

