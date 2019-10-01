/**
 * Sample input:
 * 3
 * Joe Math990112 89
 * Mike CS991301 100
 * Mary EE990830 95
 * -----------------
 * Sample output:
 * Mike CS991301
 * Joe Math990112
 */
#include <cstdio>

#define max_n 1000
#define MaxL 16

typedef struct {
	char name[MaxL];
	char id[MaxL];
	int score;
} Stu[max_n];

int main()
{
	// freopen("test.txt", "r", stdin);
	Stu stu;
	int N, i, max_i, min_i, max_score, min_score;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);

	max_score = -1; min_score = 101;
	for (i = 0; i < N; i++) {
		if (max_score < stu[i].score) {
			max_i = i;
			max_score = stu[i].score;
		}
		if (min_score > stu[i].score) {
			min_i = i;
			min_score = stu[i].score;
		}
	}
	printf("%s %s\n", stu[max_i].name, stu[max_i].id);
	printf("%s %s\n", stu[min_i].name, stu[min_i].id);

	return 0;
}

