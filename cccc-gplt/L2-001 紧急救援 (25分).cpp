#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int n, m, s, d;
int resc[510], e[510][510], dis[510], num[510], maxresc = -1;
bool vis[510];
vector<int> pre[510], path, tmppath;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == s) {
		int sum = 0;
		for (int i = 0; i < tmppath.size(); i++) sum += resc[tmppath[i]];
		if (sum > maxresc) {
			maxresc = sum;
			path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tmppath.pop_back();
}
int main() {
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++) scanf("%d", &resc[i]);
	fill(e[0], e[0] + 510*510, inf);
	fill(dis, dis + 510, inf);
	int a, b, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &wt);
		e[a][b] = e[b][a] = wt;
	}
	dis[s] = 0;
	num[s] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; v++)
			if (!vis[v] && e[u][v] != inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v]) {
					num[v] += num[u];
					pre[v].push_back(u);
				}
			}
	}
	dfs(d);
	printf("%d %d\n", num[d], maxresc);
	for (int i = path.size()-1; i >= 0; i--) {
		if (i != path.size()-1) printf(" ");
		printf("%d", path[i]);
	}
	return 0;
}
