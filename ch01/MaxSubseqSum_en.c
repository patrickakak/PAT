/**
 * PTA--Data Structures and Algorithms (English)
 * Maximum Subsequence Sum
 */
#include <stdio.h>

#define MAXK 100000
struct outcome {
	int first;
	int last;
	int MaxSum;
};

struct outcome MaxSubseqSum4(int A[], int N);

int main()
{
	int K, i, a[MAXK+1];
	struct outcome res;

	scanf("%d", &K);
	for (i = 0; i < K; i++)
		scanf("%d", &a[i]);
	res = MaxSubseqSum4(a, K);

	if (res.MaxSum >= 0)
		printf("%d %d %d\n", res.MaxSum, a[res.first], a[res.last]);
	else
		printf("%d %d %d\n", 0, a[0], a[K-1]);
	
	return 0;
}

struct outcome MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	struct outcome ret;
	int gap, i;

	ThisSum = 0, MaxSum = -1, gap = 0;
	ret.first = ret.last = ret.MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			gap++;
			/* Find the last member of the maximum subsequence */
			ret.last = i;
			ret.first = ret.last - gap + 1;
		} else if (ThisSum < 0) {
			ThisSum = 0;
			gap = 0;
		} else	/* ThisSum == MaxSum */
			gap++;
	}
	ret.MaxSum = MaxSum;

	return ret;
}

