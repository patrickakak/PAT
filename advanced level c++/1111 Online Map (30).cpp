#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x2fffffff;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510], timepre[510], weight[510], nodeNum[510];
bool vis[510];
vector<int> dispath, timepath, tmppath;
int s, d, minnode = inf;
void dfsdispath(int v) {
	dispath.push_back(v);
	if (v == s) return ;
	dfsdispath(dispre[v]);
}
void dfstimepath(int v) {
	timepath.push_back(v);
	if (v == s) return ;
	dfstimepath(timepre[v]);
}
int main() {
	fill(dis, dis + 510, inf);
	fill(Time, Time + 510, inf);
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
	Time[s] = 0;
	fill(vis, vis + 510, false);
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
			if (!vis[j] && minn > Time[j]) {
				u = j;
				minn = Time[j];
			}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; v++)
			if (!vis[v] && w[u][v] != inf) {
				if (w[u][v] + Time[u] < Time[v]) {
					Time[v] = w[u][v] + Time[u];
					timepre[v] = u;
					nodeNum[v] = nodeNum[u] + 1;
				} else if (w[u][v] + Time[u] == Time[v] && nodeNum[u] + 1 < nodeNum[v]) {
					timepre[v] = u;
					nodeNum[v] = nodeNum[u] + 1;
				}
			}
	}
	dfstimepath(d);
	printf("Distance = %d", dis[d]);
	if (dispath == timepath) printf("; Time = %d: ", Time[d]);
	else {
		printf(": ");
		for (int i = dispath.size()-1; i >= 0; i--) {
			printf("%d", dispath[i]);
			if (i != 0) printf(" -> ");
		}
		printf("\nTime = %d: ", Time[d]);
	}
	for (int i = timepath.size()-1; i >= 0; i--) {
		printf("%d", timepath[i]);
		if (i != 0) printf(" -> ");
	}
	return 0;
}
