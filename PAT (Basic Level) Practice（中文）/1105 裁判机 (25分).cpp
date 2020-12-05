#include <iostream>
#include <vector>
using namespace std;
int mp[100100], candidate[100100], out[100100];
int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<vector<int>> v(n+1, vector<int>(m+1));
	mp[a] = 1, mp[b] = 1;
	candidate[abs(a-b)] = -1;
	vector<int> w, winner;
	w.push_back(a), w.push_back(b);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &v[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			int tmp = v[j][i];
			if (out[j] == 1) continue;
			if (mp[tmp] != 0) {
				printf("Round #%d: %d is out.\n", i, j);
				out[j] = 1;
			} else {
				if (candidate[tmp] == -1) {
					mp[tmp] = 1;
					w.push_back(tmp);
					for (int l = 0; l < w.size()-1; l++) {
						int t = abs(w[l] - w[w.size()-1]);
						candidate[t] = -1;
					}
				} else if (candidate[tmp] == 0) {
					printf("Round #%d: %d is out.\n", i, j);
					out[j] = 1;
				}
			}
		}
	for (int i = 1; i <= n; i++)
		if (out[i] == 0)
			winner.push_back(i);
	if (winner.size() == 0) printf("No winner.\n");
	else {
		printf("Winner(s):");
		for (int i = 0; i < winner.size(); i++)
			printf(" %d", winner[i]);
		printf("\n");
	}
	return 0;
}
