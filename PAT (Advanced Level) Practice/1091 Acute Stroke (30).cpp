#include <iostream>
#include <queue>
using namespace std;
struct node {
	int x, y, z;
};
int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};
int m, n, l, t, a[1300][130][80];
bool inq[1300][130][80];
bool judge(int x, int y, int z) {
	if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
	if (a[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}
int bfs(int x, int y, int z) {
	int cnt = 0;
	queue<node> q;
	q.push(node{x, y, z});
	inq[x][y][z] = true;
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; i++) {
			int tx = top.x + X[i], ty = top.y + Y[i], tz = top.z + Z[i];
			if (judge(tx, ty, tz)) {
				q.push(node{tx, ty, tz});
				inq[tx][ty][tz] = true;
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
				scanf("%d", &a[j][k][i]);
	int ans = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				if (a[j][k][i] == 1 && inq[j][k][i] == false)
					ans += bfs(j, k, i);
	printf("%d", ans);
	return 0;
}
