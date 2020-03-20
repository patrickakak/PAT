#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int dis[510], tm[510], e[510][510], w[510][510], dispre[510], tmpre[510], weight[510], nodeNum[510];
bool vis[510];
vector<int> dispath, tmpath, tmppath;
int s, d, minnode = inf;
void dfsdispath(int v) {
	dispath.push_back(v);
	if (v == s) return ;
	dfsdispath(dispre[v]);
}
void dfstmpath(int v) {
	tmpath.push_back(v);
	if (v == s) return ;
	dfstmpath(tmpre[v]);
}
int main() {
	fill(dis, dis + 510, inf);
	fill(tm, tm + 510, inf);
	fill(weight, weight + 510, inf);
	fill(e[0], e[0] + 510 * 510, inf);
	fill(w[0], w[0] + 510 * 510, inf);
	int n, m, a, b, flag, len, t;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
		e[a][b] = len;
		w[a][b] = t;
		if (flag != 1) {
			e[b][a] = len;
			w[b][a] = t;
		}
	}
	scanf("%d %d", &s, &d);
	dis[s] = 0;
	for (int i = 0; i < n; i++) dispre[i] = i;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (!vis[j] && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; v++)
			if (!vis[v] && e[u][v] != inf) {
				if (e[u][v] + dis[u] < dis[v]) {
					dis[v] = e[u][v] + dis[u];
					dispre[v] = u;
					weight[v] = weight[u] + w[u][v];
				} else if (e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
					weight[v] = weight[u] + w[u][v];
					dispre[v] = u;
				}
			}
	}
	dfsdispath(d);
	tm[s] = 0;
	fill(vis, vis + 510, false);
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (!vis[j] && minn > tm[j]) {
				u = j;
				minn = tm[j];
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; v++)
			if (!vis[v] && w[u][v] != inf) {
				if (w[u][v] + tm[u] < tm[v]) {
					tm[v] = w[u][v] + tm[u];
					tmpre[v] = u;
					nodeNum[v] = nodeNum[u] + 1;
				} else if (w[u][v] + tm[u] == tm[v] && nodeNum[u]+1 < nodeNum[v]) {
					tmpre[v] = u;
					nodeNum[v] = nodeNum[u] + 1;
				}
			}
	}
	dfstmpath(d);
	printf("Distance = %d", dis[d]);
	if (dispath == tmpath) printf("; Time = %d: ", tm[d]);
	else {
		printf(": ");
		for (int i = dispath.size()-1; i >= 0; i--) {
			printf("%d", dispath[i]);
			if (i != 0) printf(" -> ");
		}
		printf("\nTime = %d: ", tm[d]);
	}
	for (int i = tmpath.size()-1; i >= 0; i--) {
		printf("%d", tmpath[i]);
		if (i != 0) printf(" -> ");
	}
	return 0;
}
