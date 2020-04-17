#include <iostream>
#include <unordered_map>
using namespace std;
int n, m, k, e[510][510];
bool vis[510];
unordered_map<int, int> mp;
void dfs(int c) {
	vis[c] = true;
	for (int i = 0; i < n; i++)
		if (!vis[i] && e[c][i] == 1) dfs(i);
}
int scc() {
	int cnt = 0;
	fill(vis, vis+n, false);
	for (int i = 0; i < n; i++)
		if (!vis[i] && mp[i] == 0) {
			dfs(i);
			cnt++;
		}
	return cnt;
}
int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	cin >> k;
	int cnt = scc();
	for (int i = 0; i < k; i++) {
		scanf("%d", &c);
		mp[c] = 1;
		for (int j = 0; j < n; j++) e[c][j] = e[j][c] = 0;
		int cnt2 = scc();
		if (cnt2 > cnt) printf("Red Alert: City %d is lost!\n", c);
		else printf("City %d is lost.\n", c);
		cnt = cnt2;
	}
	if (k == n) printf("Game Over.\n");
	return 0;
}
