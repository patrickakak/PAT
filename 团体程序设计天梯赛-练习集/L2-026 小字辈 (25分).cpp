#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[100010], ans[100010];
int maxdepth = -1;
void dfs(int rt, int depth) {
	ans[depth].push_back(rt);
	maxdepth = max(maxdepth, depth);
	for (int i = 0; i < v[rt].size(); i++)
		dfs(v[rt][i], depth+1);
}
int main() {
	int n, rt, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		v[tmp].push_back(i);
		if (tmp == -1) rt = i;
	}
	dfs(rt, 1);
	printf("%d\n", maxdepth);
	sort(ans[maxdepth].begin(), ans[maxdepth].end());
	for (int i = 0; i < ans[maxdepth].size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[maxdepth][i]);
	}
	return 0;
}
