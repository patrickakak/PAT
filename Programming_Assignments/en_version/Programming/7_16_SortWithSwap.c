/**
 * Sample Input:
 * 10
 * 3 5 7 2 6 4 9 0 8 1
 * -------------------
 * Sample Output:
 * 9
 */
#include <stdio.h>
#include <stdbool.h>

#define MAXN 100000

int main()
{
	int i, N, A[MAXN], T[MAXN];
	int j, count, Next, Total;
	bool CircleWithZero;

	scanf("%d", &N);

	/* Integers in table T[] are pointers, one can refer to the 
	 * should-be-there element by following those integers 
	 */
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		T[A[i]] = i;
	}

	/* S: Single element circle  |  K: Multiple elements circle 
	 *
	 * Note: There're two different type of multiple elements circle, 
	 * one contributes n-1 swap(i.e. including zero circle), another 
	 * contributes n+1(i.e. without zero)
	 *
	 * Total time of swap(0,*): N-S+K-2
	 */
	for (Total=0, i=0; i < N; i++) {
		CircleWithZero = false;
		if (T[i] != i) {
			/**
			 * If zero is already in position, indicating you've met a 
			 * circle without zero, so we need to do swap(0,*) first to 
			 * bring zero(i.e. the empty node) into current circle 
			 */
			if (A[0] != 0)
				CircleWithZero = true;

			j = i; count = 0;
			while (1) {
				A[j] = j;	/* Put the right number in position */
				Next = T[j]; T[j] = j; j = Next;
				count++;	/* To count how many swap in a circle */

				if (T[j] == j)	/* To indicate a loop is over */
					break;
			}
			if (CircleWithZero == true)
				Total += count-1;
			else
				Total += count+1;
		}
	}
	printf("%d\n", Total);
	return 0;
}

