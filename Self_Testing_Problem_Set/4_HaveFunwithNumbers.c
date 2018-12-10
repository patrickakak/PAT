#include <stdio.h>
#include <string.h>

#define MaxDigitNum 20

int main()
{
	char oristr[MaxDigitNum+1];
	char dblstr[MaxDigitNum+2] = "";
	int OriCnt[10+1] = {0};
	int DblCnt[10+1] = {0};

	scanf("%s", oristr);

	/* Cin: carryin, R: remainder */
	int i, A, B, R, Cin, flag = 1;

	for (Cin=0, i=strlen(oristr)-1; i >= 0; i--) {
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

