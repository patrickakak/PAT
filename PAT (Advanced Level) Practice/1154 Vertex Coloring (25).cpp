#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &v[i].first, &v[i].second);
	cin >> k;
	while (k--) {
		vector<int> a(n);
		int flag = 0;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s.insert(a[i]);
		}
		for (int i = 0; i < m; i++)
			if (a[v[i].first] == a[v[i].second]) {
				flag = 1;
				break;
			}
		if (flag == 0) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}
