/**
 * Sample input:
 * 1234567 368782971
 * -----------------
 * Sample output:
 * 3695Q8118
 */
#include <stdio.h>
#include <string.h>

char N2C[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};

int main()
{
	// freopen("test.txt", "r", stdin);
	
	char A[105], B[105], stack[105], sum;
	int len_a, len_b, i, j, c, count = 1, top = -1;

	scanf("%s %s", A, B);

	len_a = strlen(A); len_b = strlen(B);
	i = len_a - 1; j = len_b - 1;
	while (i >= 0 && j >= 0) {
		if (count%2 == 1) {
			c = (A[i]-'0') + (B[j]-'0');
			sum = N2C[c%13];
		} else {
			c = B[j] - A[i];
			if (c < 0)
				c += 10;
			sum = c + '0';
		}
		stack[++top] = sum;
		count++;
		i--; j--;
	}
	while (i >= 0) {	// If A is longer than B
		if (count % 2 == 1)
			stack[++top] = A[i];
		else {
			c = 0 - (A[i]-'0');
			if (c < 0)
				c += 10;
			sum = c + '0';
			stack[++top] = sum;
		}
		count++;
		i--;
	}
	while (j >= 0) {
		stack[++top] = B[j];
		j--;
	}
	while (top != -1)
		printf("%c", stack[top--]);

	return 0;
}

