/**
 * Sample Input:
 * 6
 * 3 65
 * 2 80
 * 1 100
 * 2 70
 * 3 40
 * 3 0
 * --------------
 * Sample Output:
 * 2 150
 */
#include <stdio.h>

#define MaxN 100000
int A[MaxN] = {0};

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i;
	int no, score;
	int index = 0, total=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d%d", &no, &score);
		A[no-1] += score;
	}
	for (i = 0; i < N; i++)
		if (A[i] > total) {
			index = i;
			total = A[i];
		}
	printf("%d %d\n", index+1, A[index]);
	return 0;
}

