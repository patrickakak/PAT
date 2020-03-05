#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
int father[1010];
int find(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA < faB) father[faB] = faA;
	else if (faA > faB) father[faA] = faB;
}
int e[1010][1010];
set<int> ans[1010];
int main() {
	int k, n, m, c, r, d;
	cin >> k >> n >> m;
	for (int i = 1; i <= n; i++) father[i] = i;
	while (m--) {
		scanf("%d%d%d", &c, &r, &d);
		e[c][r] += d;
	}
	unordered_map<int, bool> mp;
	for (int i = 1; i <= n; i++) {
		int cnt = 0, callback = 0;
		for (int j = 1; j <= n; j++)
			if (e[i][j] != 0 && e[i][j] <= 5) {
				cnt++;
				if (e[j][i] != 0) callback++;
			}
		if (cnt > k && (double)callback/cnt <= 0.2) mp[i] = true;
	}
	if (mp.size() == 0) {
		printf("None"); return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (e[i][j] != 0 && e[j][i] != 0 && mp[i] == true && mp[j] == true)
				Union(i, j);
	for (int i = 1; i <= n; i++)
		if (mp[i] == true)
			ans[find(i)].insert(i);
	for (int i = 1; i <= n; i++)
		if (father[i] == i && mp[i] == true) {
			for (auto it = ans[i].begin(); it != ans[i].end(); it++) {
				if (it != ans[i].begin()) printf(" ");
				printf("%d", *it);
			}
			printf("\n");
		}
	return 0;
}
