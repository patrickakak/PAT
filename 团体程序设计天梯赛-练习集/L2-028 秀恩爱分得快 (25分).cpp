#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m, k, sex[1010] = {0};
	cin >> n >> m;
	vector<vector<int>> v(m);
	string s, a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			cin >> s;
			int id = abs(stoi(s));
			if (s[0] != '-') sex[id] = 1;
			v[i].push_back(id);
		}
	}
	cin >> a >> b;
	int aa = abs(stoi(a)), bb = abs(stoi(b));
	if (a[0] != '-') sex[aa] = 1;
	if (b[0] != '-') sex[bb] = 1;
	double max1 = 0, max2 = 0, intimacy1[1010] = {0}, intimacy2[1010] = {0};
	for (int i = 0; i < m; i++) {
		bool flg1 = (find(v[i].begin(), v[i].end(), aa) != v[i].end());
		bool flg2 = (find(v[i].begin(), v[i].end(), bb) != v[i].end());
		if (flg1 || flg2) {
			for (int j = 0; j < v[i].size(); j++)
				if (flg1 && sex[aa]^sex[v[i][j]]) {
					intimacy1[v[i][j]] += 1.0 / v[i].size();
					max1 = max(max1, intimacy1[v[i][j]]);
				}
			for (int j = 0; j < v[i].size(); j++)
				if (flg2 && sex[bb]^sex[v[i][j]]) {
					intimacy2[v[i][j]] += 1.0 / v[i].size();
					max2 = max(max2, intimacy2[v[i][j]]);
				}
		}
	}
	if (intimacy1[bb] == max1 && intimacy2[aa] == max2)
		printf("%s %s\n", a.c_str(), b.c_str());
	else {
		for (int i = 0; i < n; i++)
			if (intimacy1[i] == max1)
				printf("%s %s%d\n", a.c_str(), sex[i] ? "" : "-", i);
		for (int i = 0; i < n; i++)
			if (intimacy2[i] == max2)
				printf("%s %s%d\n", b.c_str(), sex[i] ? "" : "-", i);
	}
	return 0;
}
