#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> v[100010];
bool vis[100010], flg;
void dfs(int u, int depth) {
	if (flg == true || depth > 5) return;
    vis[u] = true;
	for (int i = 0; i < v[u].size(); i++)
		if (!vis[v[u][i]]) dfs(v[u][i], depth+1);
		else {
			flg = true;
			break;
		}
}
int main() {
	int n, k, a, b, id, f, m;
	cin >> n;
	unordered_map<int, char> mp;
	for (int i = 0; i < n; i++) {
		char c;
		scanf("%d %c %d %d", &id, &c, &f, &m);
		mp[id] = c;
		if (f != -1) {
			mp[f] = 'M';
			v[id].push_back(f);
		}
		if (m != -1) {
			mp[m] = 'F';
			v[id].push_back(m);
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a, &b);
		if (mp[a] == mp[b]) {
			printf("Never Mind\n");
			continue;
		}
		flg = false;
		fill(vis, vis+100010, false);
		dfs(a, 1);
		dfs(b, 1);
		printf("%s\n", flg == 1 ? "No" : "Yes");
	}
	return 0;
}
