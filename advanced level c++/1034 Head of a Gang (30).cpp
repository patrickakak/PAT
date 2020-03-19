#include <iostream>
#include <map>
using namespace std;
map<string, int> s2i, ans;
map<int, string> i2s;
int idx = 1, k;
int getid(string s) {
	if (s2i[s] == 0) {
		s2i[s] = idx;
		i2s[idx] = s;
		return idx++;
	} else return s2i[s];
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMbr, int &totalwt) {
	vis[u] = true;
	numMbr++;
	if (weight[u] > weight[head]) head = u;
	totalwt += weight[u];
	for (int v = 1; v < idx; v++)
		if (!vis[v] && G[u][v] > 0)
			dfs(v, head, numMbr, totalwt);
}
void dfsTrav() {
	for (int i = 1; i < idx; i++)
		if (!vis[i]) {
			int head = i, numMbr = 0, totalwt = 0;
			dfs(i, head, numMbr, totalwt);
			if (numMbr > 2 && totalwt/2 > k) ans[i2s[head]] = numMbr;
		}
}
int main() {
	int n, w;
	cin >> n >> k;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = getid(s1);
		int id2 = getid(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	dfsTrav();
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%s %d\n", it.first.c_str(), it.second);
	return 0;
}
