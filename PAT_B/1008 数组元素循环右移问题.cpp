/**
 * Sample Input:
 * 6 2
 * 1 2 3 4 5 6
 * ------------
 * Sample Ouput:
 * 5 6 1 2 3 4
 */
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MaxL 100
int A[MaxL];

void shiftRight(int A[], int N, int M)
{
	reverse(A, A+N-M);
	reverse(A+N-M, A+N);
	reverse(A, A+N);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, M, i;

	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	shiftRight(A, N, M%N);

	for (i = 0; i < N-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);

	return 0;
}


