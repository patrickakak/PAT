#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int w;
	vector<int> child;
};
vector<node> v;
bool cmp(int a, int b) {
	return v[a].w > v[b].w;
}
int s;
vector<int> path;
void dfs(int index, int nodeNum, int sum) {
	if (sum > s) return ;
	if (sum == s) {
		if (v[index].child.size() != 0) return;
		for (int i = 0; i < nodeNum; i++)
			printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
		return ;
	}
	for (int i = 0; i < v[index].child.size(); i++) {
		int node = v[index].child[i];
		path[nodeNum] = node;
		dfs(node, nodeNum + 1, sum + v[node].w);
	}
}
int main() {
	int n, m, tmp, k;
	scanf("%d %d %d", &n, &m, &s);
	v.resize(n), path.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i].w);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &tmp, &k);
		v[tmp].child.resize(k);
		for (int j = 0; j < k; j++) scanf("%d", &v[tmp].child[j]);
		sort(v[tmp].child.begin(), v[tmp].child.end(), cmp);
	}
	dfs(0, 1, v[0].w);
	return 0;
}
