/**
 * Sample input:
 * 10
 * 60 75 90 55 75 99 82 90 75 50
 * 3 75 90 88
 * ------------------
 * Sample output:
 * 3 2 0
 */
#include <cstdio>

#define maxn 110
int hashTbl[maxn] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n, k, grade;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &grade);
		hashTbl[grade]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &grade);
		if (i > 0)
			printf(" ");
		printf("%d", hashTbl[grade]);
	}
	printf("\n");

	return 0;
}


