/**
 * Sample Input:
 * 6 2
 * 1 2 3 4 5 6
 * Sample Output:
 * 5 6 1 2 3 4
 */
#include <stdio.h>

#define MAXN 100
typedef int ElementType;

/* You can get something's chiral dual by go through a mirror change */
void Mirror(ElementType A[], int L, int R);
void Swap(ElementType *a, ElementType *b);
void RightShift(ElementType S[], int N, int M);

int main()
{
	int N, M, i, A[MAXN], flag;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	/* M can be larger than N */
	M %= N;
	RightShift(A, N, M);
	
	for (flag = 0, i = 0; i < N; i++) {
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

/* Chirality:
 *
 * Divide N elements into two parts: 0~N-M-1 and N-M~N-1.
 *
 * Elements in the same part, they go through twice mirror change, so 
 * their relative position is unchanged. However, if you see the two 
 * parts as two huge elements, both of them have only mirroed once, so 
 * the order of those two is reversed.
 */
void Mirror(ElementType A[], int L, int R)
{
	int i, j;

	for (i = L, j = R; i < j; i++, j--)
		Swap(&A[i], &A[j]);
}

/* M: right shift offset (M<N) */
void RightShift(ElementType S[], int N, int M)
{
	Mirror(S, 0, N-M-1);
	Mirror(S, N-M, N-1);
	Mirror(S, 0, N-1);
}

