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
	int a, b, cnt = 0, s1 = 0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!visit[i]) {
			dfs(i, 1);
			if (i == 1) {
				if (tmp.size() != 0) s1 = tmp[0];
				for (int j = 0; j < tmp.size(); j++) s.insert(tmp[j]);
			}
			cnt++;
		}
	if (cnt > 1) printf("Error: %d components", cnt);
	else {
		tmp.clear();
		maxheight = 0;
		fill(visit, visit + 10010, false);
		dfs(s1, 1);
		for (int i = 0; i < tmp.size(); i++) s.insert(tmp[i]);
		for (auto it = s.begin(); it != s.end(); it++) printf("%d\n", *it);
	}
	return 0;
}
