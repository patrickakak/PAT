#include <stdio.h>
#include <string.h>

#define MAXK 20
#define NumCards 54

int main()
{
	int K, i, j;
	int order[NumCards];
	int FinalPos[NumCards];
	char NewOrder[NumCards][5];
	char Strs[NumCards][5];
	char color[4] = {'S', 'H', 'C', 'D'};

	int k = 0;
	for (i = 0, k = 0; i < 4; i++, k+=13) {
		for (j = 0; j < 13; j++) {
			sprintf(Strs[j+k], "%c%d", color[i], j+1);
		}
	}
	sprintf(Strs[52], "J1");
	sprintf(Strs[53], "J2");
	
	/*
	// test
	for (i = 0; i < NumCards; i++) {
		printf(" %s", Strs[i]);
	}
	printf("\n");
	// test
	*/

	// freopen("data.txt", "r", stdin);
	scanf("%d", &K);
	for (i = 0; i < NumCards; i++) {
		scanf("%d", &order[i]);
	}

	for (i = 0; i < NumCards; i++) {
		for (FinalPos[i]=order[i]-1, j=0; j < K-1; j++) {
			FinalPos[i] = order[FinalPos[i]]-1;
		}
		// printf("NewPos=%d\n", NewPos);
	}
	for (i = 0; i < NumCards; i++) {
		//NewOrder[FinalPos[i]] = order[i];
		strcpy(NewOrder[FinalPos[i]], Strs[i]);
	}

	int flag = 0;
	for (i = 0; i < NumCards; i++) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%s", NewOrder[i]);
	}
	printf("\n");

	return 0;
}


