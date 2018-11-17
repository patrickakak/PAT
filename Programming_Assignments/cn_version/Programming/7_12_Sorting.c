/**
 * Sample Input:
 * 11
 * 4 981 10 -17 0 -20 29 50 8 43 -5
 *----------------------------------
 * Sample Output:
 * -20 -17 -5 0 4 8 10 29 43 50 981
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
typedef long ElementType;

void ReadInput(ElementType A[], long N);
void Output(ElementType A[], long N);
void Swap(ElementType *a, ElementType *b);
void PercDown(ElementType A[], long p, long N);
void Merge_pass(ElementType A[], ElementType TmpA[], long N, long length);
void Merge1(ElementType A[], ElementType TmpA[], long L, long R, long RightEnd);

void ShellSort(ElementType A[], long N);
void HeapSort(ElementType A[], long N);
void Merge_Sort(ElementType A[], long N);

int main()
{
	long N;
	ElementType *A;

	scanf("%ld", &N);

	A = (ElementType *) malloc(N * sizeof(ElementType));

	ReadInput(A, N);

	/* ShellSort(A, N); */
	/* HeapSort(A, N); */
	Merge_Sort(A, N);

	Output(A, N); putchar('\n');

	free(A);
	return 0;
}

void ShellSort(ElementType A[], long N)
{
	int Si;
	long D, i, P;
	ElementType Tmp;
	long Sedgewick[] = {64769, 36289, 16001, 8929, 3905, 
		2161, 929, 505, 209, 109, 41, 19, 5, 1, 0};

	for (Si = 0; Sedgewick[Si] >= N; Si++) ;

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) {
			Tmp = A[P];
			for (i = P; i >= D && A[i-D] > Tmp; i -= D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], long p, long N)
{
	long Parent, Child;
	ElementType X;

	X = A[p];
	for (Parent = p; (Parent*2+1) < N; Parent = Child) {
		Child = 2*Parent + 1;
		if ((Child != N-1) && (A[Child] < A[Child+1]) )
			Child++;
		if (X >= A[Child]) break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], long N)
{
	long i;

	for (i = N/2-1; i >= 0; i--)
		PercDown(A, i, N);

	for (i = N-1; i > 0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void Merge1(ElementType A[], ElementType TmpA[], long L, long R, long RightEnd)
{
	long LeftEnd, Tmp;

	LeftEnd = R - 1;
	Tmp = L;

	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
}

void Merge_pass(ElementType A[], ElementType TmpA[], long N, long length)
{
	long i, j;

	for (i = 0; i <= N-2*length; i += 2*length)
		Merge1(A, TmpA, i, i+length, i+2*length-1);

	if (i+length < N)
		Merge1(A, TmpA, i, i+length, N-1);
	else
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], long N)
{ 
	long length; 
	ElementType *TmpA;

	length = 1;
	TmpA = (ElementType *) malloc(N * sizeof(ElementType));

	if (TmpA == NULL)
		printf("No enough space!\n");
	else {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
}

void ReadInput(ElementType A[], long N)
{
	long i;
	
	for (i = 0; i < N; i++)
		scanf("%ld", &A[i]);
}

void Output(ElementType A[], long N)
{
	int i, flag = 0;

	for (i = 0; i < N; i++) {
		if (!flag) flag = 1;
		else putchar(' ');
		printf("%ld", A[i]);
	}
}

