#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, k, nv, a, b, t, j;
	scanf("%d%d", &n, &m);
	vector<int> v[n];
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(i);
		v[b].push_back(i);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		vector<int> h(m);
		scanf("%d", &nv);
		for (int j = 0; j < nv; j++) {
			scanf("%d", &t);
			for (int l = 0; l < v[t].size(); l++)
				h[v[t][l]] = 1;
		}
		for (j = 0; j < m; j++)
			if (h[j] == 0) break;
		if (j < m) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
