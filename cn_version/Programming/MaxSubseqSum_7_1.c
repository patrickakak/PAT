// PTA--Data Structures and Algorithms (Chinese version)
// 7-1 Maximum subsequence sum
#include <stdio.h>

#define MAXK 100000

int MaxSubseqSum4(int A[], int N);

int main()
{
	int K, i, a[MAXK+1];

	scanf("%d", &K);
	for (i=0; i<K; i++)
		scanf("%d", &a[i]);
	printf("%d\n", MaxSubseqSum4(a, K));
	return 0;
}

int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i=0; i<N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

