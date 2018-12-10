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

