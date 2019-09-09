/**
 * Sample input:
 * 4
 * 3310120150912233 2 4
 * 3310120150912119 4 1
 * 3310120150912126 1 3
 * 3310120150912002 3 2
 * 2
 * 3 4
 * --------------------
 * Sample output:
 * 3310120150912002 2
 * 3310120150912119 1
 */
#include <stdio.h>
#include <string.h>

#define max_n 1005
#define MAXL 20

typedef struct {
	char id[MAXL];
	int exam;
} Reg[max_n];

int main()
{
	// freopen("test.txt", "r", stdin);
	char id[MAXL];
	Reg reg;
	int N, i, M, no, trialNo, examNo;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s %d %d", id, &trialNo, &examNo);
		strcpy(reg[trialNo].id, id);
		reg[trialNo].exam = examNo;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &no);
		printf("%s %d\n", reg[no].id, reg[no].exam);
	}
	return 0;
}

