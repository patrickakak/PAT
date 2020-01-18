/**
 * Sample input:
 * 4 11 12 13 14
 * 5 9 10 15 16 17
 * ----------------
 * Sample output:
 * 13
 */
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
#define maxn 400010
LL a[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", a+i);
	scanf("%d", &m);
	for (int j = i; j < m+i; j++)
		scanf("%lld", a+j);
	sort(a, a + m + n);
	printf("%lld\n", a[(m + n - 1)/2]);

	return 0;
}


