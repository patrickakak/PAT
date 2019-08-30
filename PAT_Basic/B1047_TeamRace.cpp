/**
 * Sample input:
 * 6
 * 3-10 99
 * 11-5 87
 * 102-1 0
 * 102-3 100
 * 11-9 89
 * 3-2 61
 * ------------
 * Sample output:
 * 11 176
 */
#include <cstdio>

#define maxn 10010
int hashTbl[maxn] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	int tid, mid, score;
	for (int i = 0; i < n ;i++) {
		scanf("%d-%d %d", &tid, &mid, &score);
		hashTbl[tid] += score;
	}
	int k, Max = -1;
	for(int i = 0; i < maxn; i++)
		if (hashTbl[i] > Max) {
			k = i;
			Max = hashTbl[i];
		}
	printf("%d %d\n", k, Max);

	return 0;
}


