#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> tmp;
void dfs(int node, int height) {
	if (height > maxheight) {
		tmp.clear();
		tmp.push_back(node);
		maxheight = height;
	} else if (height == maxheight)
		tmp.push_back(node);
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++)
		if (!visit[v[node][i]])
			dfs(v[node][i], height + 1);
}
int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	int a, b, src, cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!visit[i]) {
			dfs(i, 1);
			if (i == 1) {
				if (tmp.size() != 0) src = tmp[0];
				for (auto j : tmp) s.insert(j);
			}
			cnt++;
		}
	if (cnt > 1) printf("Error: %d components", cnt);
	else {
		tmp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(src, 1);
		for (auto i : tmp) s.insert(i);
		for (auto it : s) printf("%d\n", it);
	}
	return 0;
}
