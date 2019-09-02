/**
 * Sample input:
 * 5
 * 1 3 2 4 5
 * -------------
 * Sample output:
 * 3
 * 1 4 5
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100010
const int INF = 0x3fffffff;
int a[maxn], leftMax[maxn], rightMin[maxn];
int ans[maxn], num = 0;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	leftMax[0] = 0;
	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i-1], a[i-1]);
	rightMin[n-1] = INF;
	for (int i = n-2; i >= 0; i--)
		rightMin[i] = min(rightMin[i+1], a[i+1]);
	for (int i = 0; i < n; i++)
		if (leftMax[i] < a[i] && rightMin[i] > a[i])
			ans[num++] = a[i];
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		printf("%d", ans[i]);
		if (i < num-1) printf(" ");
	}
	printf("\n");

	return 0;
}


