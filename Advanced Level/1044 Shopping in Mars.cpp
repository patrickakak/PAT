/**
 * Sample input1:
 * 16 15
 * 3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
 * Sample output1:
 * 1-5
 * 4-6
 * 7-8
 * 11-11
 * -----------------
 * Sample input2:
 * 5 13
 * 2 4 5 7 9
 * Sample output2:
 * 2-4
 * 4-5
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100010
int sum[maxn] = {0};	// sum[n]: A[1]~A[n]

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, S, nearS = 100000010;

	scanf("%d%d", &n, &S);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(sum+i, sum+n+1, sum[i-1]+S) - sum;
		if (sum[j-1] - sum[i-1] == S) {
			nearS = S;
			break;
		} else if (j <= n && sum[j]-sum[i-1] < nearS)
			nearS = sum[j] - sum[i-1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(sum+i, sum+n+1, sum[i-1]+nearS) - sum;
		if (sum[j-1] - sum[i-1] == nearS)
			printf("%d-%d\n", i, j-1);
	}

	return 0;
}


