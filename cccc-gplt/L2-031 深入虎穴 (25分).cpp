#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v(100010);
int h[100010], maxdep = -1, d[100010];
void dfs(int rt, int depth) {
	maxdep = max(maxdep, depth);
	d[depth] = rt;
	for (int i = 0; i < v[rt].size(); i++)
		dfs(v[rt][i], depth+1);
}
int main() {
	int n, k, id, rt = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &id);
			v[i].push_back(id);
			h[id] = 1;
		}
	}
	while (rt <= n && h[rt] == 1) rt++;
	dfs(rt, 0);
	printf("%d\n", d[maxdep]);
	return 0;
}
