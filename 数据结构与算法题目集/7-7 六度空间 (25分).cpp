#include <iostream>
#include <queue>
using namespace std;
struct node {
	int v, layer;
};
int n, m, G[1010][1010];
bool inq[1010];
int bfs(int v) {
	queue<node> q;
	q.push(node{v, 0});
	inq[v] = true;
	int cnt = 0;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		if (t.layer > 6) break;
		cnt++;
		for (int i = 1; i <= n; i++)
			if (!inq[i] && G[t.v][i] == 1) {
				q.push(node{i, t.layer + 1});
				inq[i] = true;
			}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	int a, b, cnt;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		fill(inq, inq + 1010, false);
		cnt = bfs(i);
		printf("%d: %.2lf%%\n", i, 100.0 * cnt / n);
	}
	return 0;
}
