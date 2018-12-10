#include <stdio.h>
#include <string.h>

#define MaxDigitNum 20

int main()
{
	char oristr[MaxDigitNum+1];		/* Original numbers in string */
	char dblstr[MaxDigitNum+2];		/* Double numbers in string  */
	int OriCnt[10] = {0};
	int DblCnt[10] = {0};

	scanf("%s", oristr);

	/* Cin: carryin, R: remainder */
	int i, A, B, R, orilen, Cin, flag = 1;

	orilen = strlen(oristr);
	dblstr[orilen] = '\0';
	for (Cin=0, i=orilen-1; i >= 0; i--) {
		A = oristr[i] - '0';
		OriCnt[A]++;
		B = 2 * A + Cin;
		R = B % 10;
		Cin = B / 10;
		dblstr[i] = R + '0';
		DblCnt[R]++;
	}
	/* Double number is in different length */
	if (Cin > 0)
		flag = 0;

	/* Check if doubling the input number gives a number that consists of 
	 * only a permutation of the digits in the original number */
	if (flag)
		for (i = 0; i < 10; i++)
			if (OriCnt[i] != DblCnt[i]) {
				flag = 0;
				break;
			}

	if (flag)
		printf("Yes\n");
	else
		printf("No\n");

	if (Cin > 0)
		printf("1");
	printf("%s\n", dblstr);

	return 0;
}

