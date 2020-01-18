/**
 * Sample input1:
 * +1.23400E-03
 * Sample output1:
 * 0.00123400
 * --------------
 * Sample input2:
 * -1.2E+10
 * Sample output2:
 * -12000000000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_L 10005

int main()
{
	// freopen("test.txt", "r", stdin);
	char sign1, sign2, integer, s[Max_L];
	int exp, len, i = 0, j = 0;

	scanf("%c%c.%s", &sign1, &integer, s);
	while (s[i]) {
		if (s[i] == 'E')
			break;
		i++;
	}
	s[i++] = '\0';
	sign2 = s[i++];

	exp = atoi(s + i);
	if (sign1 == '-')
		printf("-");

	if (sign2 == '-') {
		if (exp == 0)
			printf("%c.%s\n", integer, s);
		else {
			printf("0.");
			for (j = 0; j < exp-1; j++)
				printf("0");
			printf("%c%s\n", integer, s);
		}
	} else {
		if (exp == 0)
			printf("%c.%s\n", integer, s);
		else {
			len = strlen(s);
			if (exp >= len) {	// Need to add decimal point
				printf("%c%s", integer, s);
				for (j = 0; j < exp-len; j++)
					printf("0");
				printf("\n");
			} else {
				printf("%c", integer);
				for (j = 0; j < exp; j++)
					printf("%c", s[j]);
				printf(".");
				printf("%s", s+j);
			}
		}
	}
	return 0;
}

