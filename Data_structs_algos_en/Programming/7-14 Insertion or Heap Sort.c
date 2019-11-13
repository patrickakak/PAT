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
 * 3 1 2 8 7 5 9 4 6 0
 * 6 4 5 1 0 3 2 7 8 9
 * Sample Output2:
 * Heap Sort
 * 5 4 3 1 0 2 6 7 8 9
 * */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
typedef int ElemType;

void ReadInput(ElemType A[], int N);
void Output(ElemType A[], int N);
int IsInsertSort(ElemType A[], ElemType B[], int N);
void Swap(ElemType *a, ElemType *b);
void PercDown(ElemType A[], int p, int N);
int GetUnsortedNum(ElemType A[], int N);

void InsertionSort(ElemType A[], int p, int N);
void HeapSort(ElemType A[], int N);

int main()
{
	/* N ∈ [4, 100] (4 is the minimum N to guarantee the answer is unique) */
	int N, pos, NumUnsorted;
	ElemType A[MAXN], B[MAXN];

	scanf("%d", &N);

	ReadInput(A, N);
	ReadInput(B, N);

	pos = IsInsertSort(A, B, N);
	if (pos != -1) {
		puts("Insertion Sort");		/* Insertion sort one iteration forward */
		InsertionSort(B, pos, N);
	} else {
		puts("Heap Sort");	/* Heap sort one iteration forward */
		NumUnsorted = GetUnsortedNum(B, N);
		HeapSort(B, NumUnsorted);
	}
	Output(B, N); putchar('\n');

	return 0;
}

int GetUnsortedNum(ElemType A[], int N)
{
	int i;
	ElemType Tmp = A[0];

	for (i = 1; i < N; i++)
		if (Tmp < A[i])
			break;
	return i;
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
	for (i = p; i>0 && A[i-1]>Tmp; i--)
		A[i] = A[i-1];
	A[i] = Tmp;
}

void Swap(ElemType *a, ElemType *b)
{
	ElemType t = *a; *a = *b; *b = t;
}

void PercDown(ElemType A[], int p, int N)
{
	int Parent, Child;
	ElemType X;

	X = A[p];
	for (Parent = p; (Parent*2+1) < N; Parent = Child) {
		Child = 2*Parent + 1;
		if ((Child != N-1) && (A[Child] < A[Child+1]))
			Child++;
		if (X >= A[Child]) break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

/* Execute heap sort one iteration forward */
void HeapSort(ElemType A[], int N)
{
	Swap(&A[0], &A[N-1]);
	PercDown(A, 0, N-1);
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

