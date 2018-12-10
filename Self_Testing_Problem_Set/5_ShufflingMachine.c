/**
 * Sample Input:
 * 2
 * 36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
 * --------------------------------------------------------
 * Sample Output:
 * S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
 */
#include <stdio.h>
#include <string.h>

#define MAXK 20
#define NumCards 54
#define LEN 4

void InitialStatus(char Strs[][LEN], char Suit[4]);
void Output(char Seq[][LEN], int N);

int main()
{
	int K, i, j;
	int GivenOrder[NumCards], FinalPos[NumCards];
	char NewSeq[NumCards][LEN], Strs[NumCards][LEN];
	char Suit[4] = {'S', 'H', 'C', 'D'};

	InitialStatus(Strs, Suit);

	scanf("%d", &K);
	for (i = 0; i < NumCards; i++)
		scanf("%d", &GivenOrder[i]);

	/* Find final position of each card, K > 0 */
	for (i = 0; i < NumCards; i++)
		for (FinalPos[i] = GivenOrder[i]-1, j = 1; j < K; j++)
			FinalPos[i] = GivenOrder[FinalPos[i]] - 1;

	for (i = 0; i < NumCards; i++)
		strcpy(NewSeq[FinalPos[i]], Strs[i]);

	Output(NewSeq, NumCards);
	printf("\n");

	return 0;
}

void InitialStatus(char Strs[][LEN], char Suit[4])
{
	int i, j, k;

	for (i = 0, k = 0; i < 4; i++, k+=13)
		for (j = 0; j < 13; j++)
			sprintf(Strs[j+k], "%c%d", Suit[i], j+1);
	sprintf(Strs[52], "J1");
	sprintf(Strs[53], "J2");
}

void Output(char Seq[][LEN], int N)
{
	int i, flag;

	for (flag = 0, i = 0; i < N; i++) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%s", Seq[i]);
	}
}

