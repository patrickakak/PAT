#include <iostream>
#include <queue>
using namespace std;
struct node {
	int x, y, z;
};
int m, n, l, t;
int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};
int arr[1300][130][80];
bool vis[1300][130][80];
bool judge(int x, int y, int z) {
	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
	if (arr[x][y][z] == 0 || vis[x][y][z] == true) return false;
	return true;
}
int bfs(int x, int y, int z) {
	int cnt = 0;
	queue<node> q;
	q.push(node{x, y, z});
	vis[x][y][z] = true;
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; i++) {
			int tx = top.x + X[i], ty = top.y + Y[i], tz = top.z + Z[i];
			if (judge(tx, ty, tz)) {
				vis[tx][ty][tz] = true;
				q.push(node{tx, ty, tz});
			}
		}
	}
	return cnt >= t ? cnt : 0;
}
int main() {
	scanf("%d %d %d %d", &m, &n, &l, &t);
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				scanf("%d", &arr[j][k][i]);
	int ans = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (arr[j][k][i] == 1 && vis[j][k][i] == false)
					ans += bfs(j, k, i);
	printf("%d", ans);
	return 0;
}
