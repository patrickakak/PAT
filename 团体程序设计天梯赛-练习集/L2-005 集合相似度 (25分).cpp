#include <iostream>
#include <set>
using namespace std;
set<int> s[51];
int main() {
	int n, m, t, k, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			s[i].insert(t);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int nc = 0;
		scanf("%d%d", &a, &b);
		for (auto it = s[a].begin(); it != s[a].end(); it++)
			if (s[b].find(*it) != s[b].end()) nc++;
		int nt = s[a].size() + s[b].size() - nc;
		printf("%.2f%%\n", 100.0*nc/nt);
	}
	return 0;
}
