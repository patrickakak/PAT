/**
 * Sample Input1:
 * 10
 * 3 1 2 8 7 5 9 4 6 0
 * 1 2 3 7 8 5 9 4 6 0
 * Sample Output1:
 * Insertion Sort
 * 1 2 3 5 7 8 9 4 6 0
 * --------------------
 * Sample Input2:
 * 10
 * 3 1 2 8 7 5 9 4 0 6
 * 1 3 2 8 5 7 4 9 0 6
 * Sample Output2:
 * Merge Sort
 * 1 2 3 8 4 5 7 9 0 6
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
typedef int ElemType;

void Merge_pass(ElemType A[], ElemType TmpA[], int N, int length);
void Merge(ElemType A[], ElemType TmpA[], int L, int R, int RightEnd);
void ReadInput(ElemType A[], int N);
void Output(ElemType A[], int N);
int IsInsertSort(ElemType A[], ElemType B[], int N);
int GetMaxMergeGap(ElemType A[], int N);

void InsertionSort(ElemType A[], int p, int N);
void MergeSort(ElemType A[], int N);

int main()
{
	/* N ∈ [4, 100] (4 is the minimum N to guarantee the answer is unique) */
	int N, pos;
	ElemType A[MAXN], B[MAXN];

	scanf("%d", &N);

	ReadInput(A, N);
	ReadInput(B, N);

	pos = IsInsertSort(A, B, N);
	if (pos != -1) {
		puts("Insertion Sort");		/* Insertion sort one iteration forward */
		InsertionSort(B, pos, N);
	} else {
		puts("Merge Sort");		/* Merge sort one iteration forward */
		MergeSort(B, N);
	}
	Output(B, N);
	putchar('\n');
	return 0;
}

int IsInsertSort(ElemType A[], ElemType B[], int N)
{
	int i, j;

	for (i = 1; i < N; i++)		/* Find out the first inversion */
		if (B[i-1] > B[i]) break;
	for (j = i; j < N; j++)		/* Check whether the rest are untouched */
		if (B[j] != A[j]) break;

	if (i < N && j == N)
		return i;	/* Insertion sort, return position */
	else return -1;
}

/* Execute insertion sort one iteration forward */
void InsertionSort(ElemType A[], int p, int N)
{
	int i;
	ElemType Tmp;

	Tmp = A[p];
	for (i = p; i>=1 && A[i-1]>Tmp; i--)
		A[i] = A[i-1];
	A[i] = Tmp;
}

/* Execute merge sort one iteration forward */
void MergeSort(ElemType A[], int N)
{
	ElemType *TmpA;
	int gap;

	TmpA = (ElemType *) malloc(N * sizeof(ElemType));

	if (TmpA == NULL)
		puts("Not enough memory!");
	else {
		gap = GetMaxMergeGap(A, N);
		if (gap < N)
			Merge_pass(A, TmpA, N, gap);
		free(TmpA);
	}
}

/* Find out the minimum merge gap of current A[] */
int GetMaxMergeGap(ElemType A[], int N)
{
	int i, gap, flag = 0;

	for (gap = 2; gap <= N; gap *= 2) {
		for (i = 0; i <= N-2*gap; i += 2*gap) 	/* Same as merge procedure */
			if (A[i+gap-1] > A[i+gap])
				flag = 1;
		if (flag) break;
	}
	return gap;
}

void Merge_pass(ElemType A[], ElemType TmpA[], int N, int length)
{
	int i;

	for (i = 0; i <= N-2*length; i += 2*length)
		Merge(A, TmpA, i, i+length, i+2*length-1);
	if (i+length < N)
		Merge(A, TmpA, i, i+length, N-1);
}

void Merge(ElemType A[], ElemType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp, i;

	LeftEnd = R - 1;
	Tmp = L;
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

void ReadInput(ElemType A[], int N)
{
	int i;

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
}

void Output(ElemType A[], int N)
{
	int i, flag = 0;

	for (i = 0; i < N; i++) {
		if (!flag) flag = 1;
		else putchar(' ');
		printf("%d", A[i]);
	}
}

