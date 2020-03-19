#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int cmax, n, sp, m, minSend = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool vis[510];
vector<int> pre[510], path, tmppath;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == 0) {
		int send = 0, back = 0;
		for (int i = tmppath.size() - 2; i >= 0; i--) {
			int id = tmppath[i];
			if (weight[id] > 0) back += weight[id];
			else {
				if (back > (0 - weight[id])) back += weight[id];
				else {
					send += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (send < minSend) {
			minSend = send;
			minBack = back;
			path = tmppath;
		} else if (send == minSend && back < minBack) {
			minBack = back;
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
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] -= cmax / 2;
	}
	int a, b, t;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &t);
		e[b][a] = e[a][b] = t;
	}
	dis[0] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++)
			if (!vis[j] && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v <= n; v++)
			if (!vis[v] && e[u][v] != inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
	}
	dfs(sp);
	printf("%d 0", minSend);
	for (int i = path.size()-2; i >= 0; i--) printf("->%d", path[i]);
	printf(" %d", minBack);
	return 0;
}
