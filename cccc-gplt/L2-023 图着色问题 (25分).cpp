#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
	int v, e, k, n, a, b, g[510][510];
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> colour(v+1);
		unordered_set<int> s;
		for (int j = 1; j <= v; j++) {
			scanf("%d", &colour[j]);
			s.insert(colour[j]);
		}
		if (s.size() != k) printf("No\n");
		else {
			int flg = 1;
			for (int j = 1; j <= v; j++)
				for (int l = 1; l <= v; l++)
					if (g[j][l] == 1 && colour[j] == colour[l])
						flg = 0;
			printf("%s\n", flg == 0 ? "No" : "Yes");
		}
	}
	return 0;
}
