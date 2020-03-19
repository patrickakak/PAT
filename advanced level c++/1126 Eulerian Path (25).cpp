#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<bool> vis;
int cnt = 0;
void dfs(int idx) {
	vis[idx] = true;
	cnt++;
	for (int i = 0; i < v[idx].size(); i++)
		if (!vis[v[idx][i]])
			dfs(v[idx][i]);
}
int main() {
	int n, m, a, b, even = 0;
	scanf("%d%d", &n, &m);
	v.resize(n + 1), vis.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1) printf(" ");
		printf("%d", v[i].size());
		if (v[i].size() % 2 == 0) even++;
	}
	printf("\n");
	dfs(1);
	if (even == n && cnt == n) printf("Eulerian");
	else if (even == n-2 && cnt == n) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
