#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	vector<int> child;
};
int n, m, s;
vector<int> w, path;
vector<node> v;
bool cmp(int a, int b) {
	return w[a] > w[b];
}
void dfs(int idx, int sum) {
	if (sum > s) return;
	if (sum == s) {
		path.push_back(w[idx]);
		if (v[idx].child.size() == 0)
			for (int i = 0; i < path.size(); i++)
				printf("%d%s", path[i], i == path.size()-1 ? "\n" : " ");
		path.pop_back();
		return;
	}
	path.push_back(w[idx]);
	for (int i = 0; i < v[idx].child.size(); i++)
		dfs(v[idx].child[i], sum + w[v[idx].child[i]]);
	path.pop_back();
}
int main() {
	cin >> n >> m >> s;
	v.resize(n), w.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) {
		int id, k, tmp;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			v[id].child.push_back(tmp);
		}
		sort(v[id].child.begin(), v[id].child.end(), cmp);
	}
	dfs(0, w[0]);
	return 0;
}
