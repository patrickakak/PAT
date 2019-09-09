/**
 * Sample input1:
 * 3
 * Itai nyan~
 * Ninjin wa iyadanyan~
 * uhhh nyan~
 * Sample output1:
 * nyan~
 * ----------------
 * Sample input2:
 * 3
 * Itai!
 * Ninjinnwaiyada T_T
 * T_T
 * Sample output2:
 * nai
 */
#include <stdio.h>
#include <string.h>

#define Arr_Len 105
#define Max_L 260

char line[Arr_Len][Max_L];
int len[Arr_Len];

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a; *a = *b; *b = tmp;
}

void reverse(char a[], int n)
{
	int i, j;
	for (i=0, j=n-1; i < j; i++, j--)
		swap(&a[i], &a[j]);
}

int main()
{
	//freopen("test.txt", "r", stdin);
	int N, i, j, min_len;
	char ch;

	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		gets(line[i]);
		len[i] = strlen(line[i]);
	}
	min_len = Max_L;
	for (i = 0; i < N; i++)
		if (min_len > len[i])
			min_len = len[i];
	for (i = 0; i < N; i++)
		reverse(line[i], len[i]);
	for (i = 0; i < min_len; i++) {
		ch = line[0][i];
		for (j = 1; j < N; j++)
			if (line[j][i] != ch)
				break;
		if (j < N)
			break;
	}
	if (i == 0)
		printf("nai\n");
	else {
		line[0][i] = '\0';
		reverse(line[0], strlen(line[0]));
		printf("%s\n", line[0]);
	}

	return 0;
}

