/**
 * Sample Input:
 * 5 1 2 4 14 9
 * 3
 * 1 3
 * 2 5
 * 4 1
 * Sample Output:
 * 3
 * 10
 * 7
 */
#include <stdio.h>

#define MaxN 100000
int D[MaxN];
int dis[MaxN] = {0};

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i, total = 0;
	int M, ex1, ex2, tmp, diff;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &D[i]);
		dis[i] = total;
		total += D[i];
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &ex1, &ex2);
		if (ex1 > ex2) {
			tmp = ex1;
			ex1 = ex2;
			ex2 = tmp;
		}
		diff = dis[ex2-1] - dis[ex1-1];
		printf("%d\n", (diff < total-diff ? diff : total-diff));
	}

	return 0;
}


