/**
 * Sample input1:
 * 3
 * Joe M Math990112 89
 * Mike M CS991301 100
 * Mary F EE990830 95
 * Sample output1:
 * Mary EE990830
 * Joe Math990112
 * 6
 * ------------------
 * Sample input2:
 * 1
 * Jean M AA980920 60
 * Sample output2:
 * Absent
 * Jean AA980920
 * NA
 */
#include <stdio.h>

typedef struct {
	char name[11];
	char gender;
	char id[11];
	int grade;
} person;

person p, lowestM, highestF;

void init()
{
	lowestM.grade = 101;
	highestF.grade = -1;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i;

	init();
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s %c %s %d", p.name, &p.gender, p.id, &p.grade);
		if (p.gender == 'M' && lowestM.grade > p.grade)
			lowestM = p;
		if (p.gender == 'F' && highestF.grade < p.grade)
			highestF = p;
	}
	if (highestF.grade == -1)
		printf("Absent\n");
	else
		printf("%s %s\n", highestF.name, highestF.id);
	if (lowestM.grade == 101)
		printf("Absent\n");
	else
		printf("%s %s\n", lowestM.name, lowestM.id);

	if (highestF.grade == -1 || lowestM.grade == 101)
		printf("NA\n");
	else
		printf("%d\n", highestF.grade-lowestM.grade);

	return 0;
}

