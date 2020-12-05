#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
	int n, m, a, b, cnt, k, e[210][210] = {0};
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	cin >> cnt;
	while (cnt--) {
		scanf("%d", &k);
		vector<int> v(k);
		unordered_set<int> s;
		int flag1 = 1, flag2 = 1;
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		if (s.size() != n || k-1 != n || v[0] != v[k-1]) flag1 = 0;
		for (int i = 0; i < k-1; i++)
			if (e[v[i]][v[i+1]] == 0) flag2 = 0;
		printf("%s\n", flag1 && flag2 ? "YES" : "NO");
	}
	return 0;
}
