/**
 * Sample Input:
 * 6 2
 * 1 2 3 4 5 6
 * Sample Output:
 * 5 6 1 2 3 4
 */
#include <stdio.h>
#include <stdbool.h>

#define MAXN 100
typedef int ElementType;

/* You can get something's chiral dual by go through a mirror change */
void Mirror(ElementType A[], int L, int R);
void Swap(ElementType *a, ElementType *b);

int main()
{
	int N, M, i, A[MAXN], flag;

	scanf("%d %d", &N, &M);
	/* M can be larger than N */
	M %= N;
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	/* Chirality */
	Mirror(A, 0, N-M-1);
	Mirror(A, N-M, N-1);
	Mirror(A, 0, N-1);
	flag = 0;
	for (i = 0; i < N; i++) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	return 0;
}

void Swap(int *a, int *b)
{
	int tmp;

	tmp = *a; *a = *b; *b = tmp;
}

void Mirror(ElementType A[], int L, int R)
{
	int i, j, Centre;

	Centre = (L + R)/2;
	for (i=L, j=R; i <= Centre; i++, j--)
		Swap(&A[i], &A[j]);
}

