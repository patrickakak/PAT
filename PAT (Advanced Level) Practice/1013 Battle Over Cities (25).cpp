#include <iostream>
#include <algorithm>
using namespace std;
int n, e[1010][1010];
bool vis[1010];
void dfs(int cid) {
	vis[cid] = true;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && e[cid][i] == 1) dfs(i);
}
int main() {
	int m, k, a, b;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	for (int i = 0; i < k; i++) {
		fill(vis, vis + 1010, false);
		scanf("%d", &a);
		int cnt = 0;
		vis[a] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				dfs(j);
				cnt++;
			}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
