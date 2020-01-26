
#include <cstdio>
#include <set>
using namespace std;

const int maxn=55;
set<int> s[maxn];
int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, tmp, k, a, b, nc, nt;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			s[i].insert(tmp);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		nc = 0;
		scanf("%d%d", &a, &b);
		for (set<int>::iterator it=s[a].begin(); it != s[a].end(); it++)
			if (s[b].find(*it) != s[b].end())
				nc++;
		nt = s[a].size() + s[b].size() - nc;
		printf("%.1f%%\n", 100.0*nc/nt);
	}
	return 0;
}


