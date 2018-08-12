#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000
int A[MAXN], T[MAXN];

int compar(const void *a, const void *b);
void solve(int ALeft, int ARight, int TRoot);
int GetLeftLength(int n);
int min(int A, int B);

int main()
{
	int N, i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	qsort(A, N, sizeof(int), compar);

	solve(0, N-1, 0);

	printf("%d", T[0]);
	for (i = 1; i < N; i++)
		printf(" %d", T[i]);
	putchar('\n');

	return 0;
}

int compar(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void solve(int ALeft, int ARight, int TRoot)
{
	// Initial call: solve(0, N-1, 0)
	int n, L, LeftTRoot, RightTRoot;

	n = ARight - ALeft + 1;		// Get the problem size
	if (n == 0) return;

	L = GetLeftLength(n);
	T[TRoot] = A[ALeft + L];

	LeftTRoot = 2 * TRoot + 1;
	RightTRoot = LeftTRoot + 1;
	solve(ALeft, ALeft+L-1, LeftTRoot);
	solve(ALeft+L+1, ARight, RightTRoot);
}

/* n = 2^H - 1 + X,  H = [log2(N+1-X)] --> H = [log2(N+1)] */
int GetLeftLength(int n)
{
	int H, L, X, Tmp; 		// H: height of perfect tree

	H = (int) floor(log2(n+1));
	Tmp = (int) pow(2, H-1);	// Tmp = 2^(H-1)
	X = n - 2*Tmp + 1;		// X = n - 2^H + 1
	X = min(X, Tmp);
	L = Tmp - 1 + X;		// L = 2^(H-1) - 1 + X

	return L;
}

int min(int A, int B)
{
	return A < B ? A : B;
}
