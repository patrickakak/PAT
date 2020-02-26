#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
struct node {
	int id, g[4], r[4];
};
int flag;
bool cmp(node a, node b) { return a.g[flag] > b.g[flag]; }
int main() {
	int n, m, id;
	cin >> n >> m;
	vector<node> v(n);
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &v[i].id, &v[i].g[1], &v[i].g[2], &v[i].g[3]);
		v[i].g[0] = v[i].g[1] + v[i].g[2] + v[i].g[3];
		s.insert(v[i].id);
	}
	for (flag = 0; flag < 4; flag++) {
		sort(v.begin(), v.end(), cmp);
		v[0].r[flag] = 1;
		for (int j = 1; j < n; j++) {
			v[j].r[flag] = j + 1;
			if (v[j].g[flag] == v[j-1].g[flag]) v[j].r[flag] = v[j-1].r[flag];
		}
	}
	string str = "ACME";
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		if (s.find(id) == s.end()) {
			printf("N/A\n"); continue;
		}
		for (int j = 0; j < n; j++)
			if (v[j].id == id) {
				int p = min_element(v[j].r, v[j].r + 4) - v[j].r;
				printf("%d %c\n", v[j].r[p], str[p]);
				break;
			}
	}
	return 0;
}
