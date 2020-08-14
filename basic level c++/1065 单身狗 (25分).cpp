#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	int n, m, a, b;
	cin >> n;
	unordered_map<int, int> partner, coming;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		partner[a] = b, partner[b] = a;
	}
	cin >> m;
	vector<int> peo(m), ans;
	for (int i = 0; i < m; i++) {
		scanf("%d", &peo[i]);
		coming[peo[i]] = 1;
	}
	for (int i = 0; i < m; i++)
		if (coming[partner[peo[i]]] != 1)
			ans.push_back(peo[i]);
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%05d", ans[i]);
	}
	return 0;
}
