#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool e[10000][10000];
typedef pair<int, int> p;
bool cmp(p &a, p &b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<int> v[10000];
	for (int i = 0; i < m; i++) {
		string aa, bb;
		cin >> aa >> bb;
		int a = abs(stoi(aa)), b = abs(stoi(bb));
		if (aa.length() == bb.length()) {
			v[a].push_back(b);
			v[b].push_back(a);
		}
		e[a][b] = e[b][a] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int c, d;
		scanf("%d%d", &c, &d);
		c = abs(c), d = abs(d);
		vector<p> ans;
		for (int j = 0; j < v[c].size(); j++)
			for (int k = 0; k < v[d].size(); k++) {
				if (v[c][j] == d || c == v[d][k]) continue;
				if (e[v[c][j]][v[d][k]] == true)
					ans.push_back({v[c][j], v[d][k]});
			}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++)
			printf("%04d %04d\n", ans[j].first, ans[j].second);
	}
	return 0;
}
