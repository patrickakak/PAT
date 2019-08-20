/**
 * Maximum Subsequence Sum
 * (T = O(N) by using dynamic programming)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn];

int main()
{
	// 6
	// -2 11 -4 13 -5 -2
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	dp[0] = A[0];
	for (int i = 1; i < n; i++)
		dp[i] = max(A[i], dp[i-1]+A[i]);

	int k = 0;
	for (int i = 1; i < n; i++)
		if (dp[i] > dp[k])
			k = i;
	printf("%d\n", dp[k]);

	return 0;
}


