/**
 * Sample input1:
 * 8 15
 * 1 2 8 7 2 4 11 15
 * Sample output1:
 * 4 11
 * ----------------
 * Sample input2:
 * 7 14
 * 1 8 7 2 4 11 15
 * Sample output2:
 * No Solution
 */
#include <cstdio>

#define maxn 1005
int hashTbl[maxn] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, a;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		++hashTbl[a];
	}
	for (int i = 1; i < m; i++)
		if (hashTbl[i] && hashTbl[m-i]) {
			if (i == m-i && hashTbl[i] <= 1)
				continue;
			printf("%d %d\n", i, m-i);
			return 0;
		}
	printf("No Solution\n");

	return 0;
}


