#include <iostream>
#include <queue>
using namespace std;
int n, e, G[10][10];
bool visit[10];
void dfs(int v) {
	visit[v] = true;
	printf(" %d", v);
	for (int i = 0; i < n; i++)
		if (!visit[i] && G[v][i] == 1) dfs(i);
}
void dfsTrav(int v) {
	if (visit[v]) return;
	printf("{");
	dfs(v);
	printf(" }\n");
}
bool inq[10];
void bfs(int v) {
	queue<int> q;
	q.push(v);
	inq[v] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		printf(" %d", t);
		for (int i = 0; i < n; i++)
			if (!inq[i] && G[t][i] == 1) {
				q.push(i);
				inq[i] = true;
			}
	}
}
void bfsTrav(int v) {
	if (inq[v]) return;
	printf("{");
	bfs(v);
	printf(" }\n");
}
int main() {
	cin >> n >> e;
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	for (int i = 0; i < n; i++) dfsTrav(i);
	for (int i = 0; i < n; i++) bfsTrav(i);
	return 0;
}
