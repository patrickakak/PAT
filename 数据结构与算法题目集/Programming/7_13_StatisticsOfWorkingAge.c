/**
 * Sample Input:
 * 8
 * 10 2 0 5 7 2 5 2
 * Sample Output:
 * 0:1
 * 2:3
 * 5:2
 * 7:1
 * 10:1
 */
#include <stdio.h>

#define MAXN 100000
#define Radix 51

typedef int ElementType;
typedef ElementType Bucket[Radix];

void InitBucket(Bucket B, int N);
void BucketSort(Bucket B, int N);
void Output(ElementType A[], int N);
int GetRemainder(int X, int N);

int main()
{
	int N;
	Bucket B;

	InitBucket(B, Radix);

	scanf("%d", &N);

	BucketSort(B, N);

	Output(B, Radix);

	return 0;
}

void InitBucket(Bucket B, int N)
{
	int i;

	for (i = 0; i < N; i++)
		B[i] = 0;
}

void BucketSort(Bucket B, int N)
{
	int i, X, R;

	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		R = GetRemainder(X, Radix);
		B[R]++;
	}
}

void Output(Bucket B, int N)
{
	int i;

	for (i = 0; i < N; i++)
		if (B[i])
			printf("%d:%d\n", i, B[i]);
}

int GetRemainder(int X, int N)
{
	return X % N;
}

