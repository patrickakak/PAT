#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct node {
	double x, y;
} c[110];
const int inf = 0x3fffffff;
int n, e[110][110], dis[110], jumpcnt = inf;
double d;
bool visit[110];
vector<int> pre[110], path, tmppath;
bool firJump(int v) {
	return (d + 7.5) * (d + 7.5) >= c[v].x * c[v].x + c[v].y * c[v].y;
}
bool jump(int a, int b) {
	return d * d >= pow(c[a].x-c[b].x, 2) + pow(c[a].y-c[b].y, 2);
}
bool isSafe(int v) {
	return (fabs(c[v].x) + d >= 50) || (fabs(c[v].y) + d >= 50);
}
void dfs(int v) {
	tmppath.push_back(v);
	if (v == 0) {
		if (tmppath.size() < jumpcnt) {
			jumpcnt = tmppath.size();
			path = tmppath;
		} else if (tmppath.size() == jumpcnt) {
			int u = tmppath[tmppath.size()-2];
			int w = path[path.size()-2];
			if (pow(c[u].x, 2)+pow(c[u].y, 2) < pow(c[w].x, 2)+pow(c[w].y, 2))
				path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tmppath.pop_back();
}
int main() {
	fill(e[0], e[0] + 110 * 110, inf);
	fill(dis, dis + 110, inf);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> c[i].x >> c[i].y;
	if (7.5 + d >= 50) {
		printf("1"); return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (firJump(i)) e[0][i] = e[i][0] = 1;
		for (int j = 1; j <= n; j++)
			if (i != j && jump(i, j)) e[i][j] = 1;
	}
	dis[0] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++)
			if (!visit[j] && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v <= n; v++)
			if (!visit[v] && e[u][v] != inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
	}
	for (int i = 1; i <= n; i++)
		if (isSafe(i)) dfs(i);
	if (jumpcnt == inf) printf("0");
	else {
		printf("%d\n", jumpcnt);
		for (int i = path.size() - 2; i >= 0; i--)
			printf("%d %d\n", (int)c[path[i]].x, (int)c[path[i]].y);
	}
	return 0;
}
