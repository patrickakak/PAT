#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int cnt[100], maxdepth = -1;
void dfs(int idx, int depth) {
	if (v[idx].size() == 0) {
		cnt[depth]++;
		maxdepth = max(maxdepth, depth);
		return ;
	}
	for (int i = 0; i < v[idx].size(); i++)
		dfs(v[idx][i], depth + 1);
}
int main() {
	int n, m, k, node, c;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &node, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &c);
			v[node].push_back(c);
		}
	}
	dfs(1, 0);
	printf("%d", cnt[0]);
	for (int i = 1; i <= maxdepth; i++)
		printf(" %d", cnt[i]);
	return 0;
}
