#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	int n, m, cnt = 0, sum = 0;
	cin >> n;
	unordered_map<string, int> mp;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	vector<pair<string, int>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
		sum += v[i].second;
	}
	sum /= m;
	vector<string> w;
	for (int i = 0; i < m; i++)
		if (v[i].second > sum && mp[v[i].first] == 0) {
			w.push_back(v[i].first);
			cnt++;
		}
	sort(w.begin(), w.end());
	if (cnt == 0) printf("Bing Mei You\n");
	else for (int i = 0; i < cnt; i++) printf("%s\n", w[i].c_str());
	return 0;
}
