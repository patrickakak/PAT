#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s, d;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 0x3fffffff;
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int c1, c2, l;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &c1, &c2, &l);
		e[c1][c2] = e[c2][c1] = l;
	}
	dis[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
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
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				} else if (dis[u] + e[u][v] == dis[v]) {
					num[v] += num[u];
					if (w[u] + weight[v] > w[v]) w[v] = w[u] + weight[v];
				}
			}
	}
	printf("%d %d", num[d], w[d]);
	return 0;
}
