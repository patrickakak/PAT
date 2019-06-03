/**
 * Sample Input:
 * 20
 * Sample Output:
 * 4
 */
#include <stdio.h>

#define MAXN 100000
typedef enum {false, true} bool;

bool IsPrime(int N);

int main()
{
	int N, A, B, DualCnt, i;

	scanf("%d", &N);
	for (DualCnt=0, A=3, i=3; i <= N; i++)
		if (IsPrime(i)) {
			B = i;
			if (B-A == 2)
				DualCnt++;
			A = B;
		}
	printf("%d\n", DualCnt);
	return 0;
}

bool IsPrime(int N)
{
	int i;

	for (i = 2; i*i <= N; i++)
		if (!(N%i)) break;
	if (i*i > N)
		return true;
	else
		return false;
}

