/**
 * Sample input:
 * 10 8
 * 2 3 20 4 5 1 6 7 8 9
 * ----------------------
 * Sample output:
 * 8
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(a+i+1, a+n, (long long)a[i]*p) - a;
		ans = max(ans, j-i);
	}
	printf("%d\n", ans);

	return 0;
}


