#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
int sum[maxn] = {0};
int main() {
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
