#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool e[10000][10000];
typedef pair<int, int> p;
bool cmp(p a, p b) {
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<int> v[10000];
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (a.length() == b.length()) {
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		e[abs(stoi(a))][abs(stoi(b))] = e[abs(stoi(b))][abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int c, d;
		scanf("%d%d", &c, &d);
		vector<p> ans;
		for (int j = 0; j < v[abs(c)].size(); j++)
			for (int k = 0; k < v[abs(d)].size(); k++) {
				if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
				if (e[v[abs(c)][j]][v[abs(d)][k]] == true)
					ans.push_back({v[abs(c)][j], v[abs(d)][k]});
			}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (int j = 0; j < ans.size(); j++)
			printf("%04d %04d\n", ans[j].first, ans[j].second);
	}
	return 0;
}
