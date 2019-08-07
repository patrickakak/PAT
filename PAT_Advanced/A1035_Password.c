/**
 * Sample input1:
 * 3
 * Team000002 Rlsp0dfa
 * Team000003 perfectpwd
 * Team000001 R1spOdfa
 * Sample output1:
 * 2
 * Team000002 RLsp%dfa
 * Team000001 R@spodfa
 * -------------------
 * Sample input2:
 * 1
 * team110 abcdefg332
 * Sample output2:
 * There is 1 account and no account is modified
 * -------------------
 * Sample input3:
 * 2
 * team110 abcdefg222
 * team220 abcdefg333
 * Sample output3:
 * There are 2 accounts and no account is modified
 */
#include <stdio.h>

#define Len 1005
#define Max_L 16

typedef struct {
	char name[Max_L];
	char pwd[Max_L];
	int modified;
} account[Len];

account acc;

int main()
{
	//freopen("test.txt", "r", stdin);

	int N, i, j;
	int count=0;
	int flag=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s %s", acc[i].name, acc[i].pwd);
		j = 0;
		while (acc[i].pwd[j]) {
			flag = 0;
			switch (acc[i].pwd[j]) {
			case '1':
			case '0':
			case 'l':
			case 'O': flag = 1; break;
			}
			if (flag) {
				count++;
				acc[i].modified = 1;
				break;
			}
			j++;
		}
	}
	for (i = 0; i < N; i++) {
		j = 0;
		while (acc[i].pwd[j]) {
			flag = 0;
			switch (acc[i].pwd[j]) {
			case '1': acc[i].pwd[j] = '@'; break;
			case '0': acc[i].pwd[j] = '%'; break;
			case 'l': acc[i].pwd[j] = 'L'; break;
			case 'O': acc[i].pwd[j] = 'o'; break;
			}
			j++;
		}
	}

	if (count == 0) {
		if (N == 1)
			printf("There is %d account and no account is modified\n", N);
		else
			printf("There are %d accounts and no account is modified\n", N);
		return 0;
	}
	printf("%d\n", count);
	for (i = 0; i < N; i++)
		if (acc[i].modified)
			printf("%s %s\n", acc[i].name, acc[i].pwd);

	return 0;
}

