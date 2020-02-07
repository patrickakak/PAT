#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3fffffff;
int e[510][510], dis[510], cost[510][510];
vector<int> pre[510];
bool visit[510];
vector<int> path, tmppath;
int n, m, s, d, mincost = inf;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == s) {
		int tmpcost = 0;
		for (int i = tmppath.size() - 1; i > 0; i--) {
			int id = tmppath[i], nextid = tmppath[i-1];
			tmpcost += cost[id][nextid];
		}
		if (tmpcost < mincost) {
			mincost = tmpcost;
			path = tmppath;
		}
		tmppath.pop_back();
		return ;
	}
	for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tmppath.pop_back();
}
int main() {
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < m; i++) {
		int a, b, d, c;
		scanf("%d%d%d%d", &a, &b, &d, &c);
		e[b][a] = e[a][b] = d;
		cost[b][a] = cost[a][b] = c;
	}
	pre[s].push_back(s);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
	}
	dfs(d);
	for (int i = path.size() - 1; i >= 0; i--) printf("%d ", path[i]);
	printf("%d %d", dis[d], mincost);
	return 0;
}
