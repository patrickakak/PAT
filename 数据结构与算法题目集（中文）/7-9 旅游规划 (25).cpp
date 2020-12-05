#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int n, m, s, d, e[510][510], dis[510], c[510][510], mincost = inf;
bool visit[510];
vector<int> pre[510], tmppath, path;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == s) {
		int cost = 0;
		for (int i = tmppath.size()-1; i > 0; i--) {
			int c1 = tmppath[i], c2 = tmppath[i-1];
			cost += c[c1][c2];
		}
		if (cost < mincost) {
			mincost = cost;
			path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tmppath.pop_back();
}
int main() {
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	fill(c[0], c[0] + 510 * 510, inf);
	cin >> n >> m >> s >> d;
	int c1, c2, l, cost;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &c1, &c2, &l, &cost);
		e[c1][c2] = e[c2][c1] = l;
		c[c1][c2] = c[c2][c1] = cost;
	}
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (!visit[j] && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
			if (!visit[v] && e[u][v] != inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
	}
	dfs(d);
	printf("%d %d", dis[d], mincost);
	return 0;
}
