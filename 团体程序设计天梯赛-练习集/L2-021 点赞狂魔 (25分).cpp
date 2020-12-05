#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
struct node {
	string s;
	int a, b;
};
bool cmp(node &a, node &b) {
	return a.a != b.a ? a.a > b.a : a.b < b.b;
}
int main() {
	int n, k, tmp;
	string s;
	cin >> n;
	unordered_map<string, unordered_set<int>> m;
	vector<node> v;
	for (int i = 0; i<n; i++) {
		cin >> s >> k;
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			m[s].insert(tmp);
		}
		v.push_back({s, m[s].size(), k});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < 3; i++) {
		if (i != 0) printf(" ");
		if (i < v.size()) printf("%s", v[i].s.c_str());
		else printf("-");
	}
	return 0;
}
