/* Sample Input:
 * 6
 * -2 11 -4 13 -5 -2
 * Sample Output: 
 * 20
 */
#include <stdio.h>

#define MAXK 100000

int MaxSubseqSum(int A[], int K);

int main()
{
	int K, i, a[MAXK];

	scanf("%d", &K);
	for (i = 0; i < K; i++)
		scanf("%d", &a[i]);
	printf("%d\n", MaxSubseqSum(a, K));

	return 0;
}

/* Online processing, T=O(N) */
int MaxSubseqSum(int A[], int K)
{
	int i, ThisSum, MaxSum;

	ThisSum = MaxSum = 0;
	for (i = 0; i < K; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		/* MaxSum is no less than 0, so we use 'else if' branch statement */
		else if (ThisSum < 0)
			ThisSum = 0; 	/* Start over */
	}
	return MaxSum;
}

