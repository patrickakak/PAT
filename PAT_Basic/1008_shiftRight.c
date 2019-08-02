/**
 * Sample Input:
 * 6 2
 * 1 2 3 4 5 6
 * ------------
 * Sample Ouput:
 * 5 6 1 2 3 4
 */
#include <stdio.h>

#define MaxL 100
int A[MaxL];

void swap(int *a, int *b)
{
	int t;
	t = *a; *a = *b; *b = t;
}

void reverse(int A[], int l, int r)
{
	int i, j;
	for (i=l, j=r; i < j; i++, j--) {
		swap(&A[i], &A[j]);
	}
}

void shiftRight(int A[], int N, int M)
{
	reverse(A, 0, N-M-1);
	reverse(A, N-M, N-1);
	reverse(A, 0, N-1);
}

int main()
{
	// freopen("test.txt", "r", stdin);
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

