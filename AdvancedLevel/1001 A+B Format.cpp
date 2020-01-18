/**
 * Sample input:
 * -1000000 9
 * -------------
 * Sample output:
 * -999,991
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	char stack[20];
	int a, b, c, r, count, top = -1;

	scanf("%d %d", &a, &b);

	c = a + b;
	if (c < 0) {
		printf("-");
		c = -c;
	}
	do {
		r = c % 10;
		stack[++top] = r + '0';
		c /= 10;
	} while (c);

	count = 0;
	while (top != -1) {
		printf("%c", stack[top]);
		count++;
		if (top%3 == 0 && top != 0)
			printf(",");
		top--;
	}

	return 0;
}

