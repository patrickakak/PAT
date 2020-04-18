#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> v[10010];
bool e[10010][10010], vis[10010];
void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < v[u].size(); i++)
		if (!vis[v[u][i]] && e[u][v[u][i]] == true)
			dfs(v[u][i]);
}
int main() {
	int n, m, k, a, b, np;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
		e[a][b] = e[b][a] = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &np);
		unordered_map<int, int> mp;
		vector<int> tmp(np);
		for (int j = 0; j < np; j++) scanf("%d", &tmp[j]);
		for (int j = 0; j < np; j++) {
			mp[tmp[j]] = 1;
			for (int l = 0; l < v[tmp[j]].size(); l++)
				e[tmp[j]][v[tmp[j]][l]] = e[v[tmp[j]][l]][tmp[j]] = false;
		}
		int cnt = 0;
		fill(vis+1, vis+1+n, false);
		for (int j = 1; j <= n; j++)
			if (!vis[j] && mp[j] != 1) {
				dfs(j);
				cnt++;
			}
		printf("%s\n", cnt+np == n ? "YES" : "NO");
		for (int j = 0; j < np; j++)
			for (int l = 0; l < v[tmp[j]].size(); l++)
				e[tmp[j]][v[tmp[j]][l]] = e[v[tmp[j]][l]][tmp[j]] = true;
	}
	return 0;
}
