#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100], d(100);
int num = 0, dmax = 1;
void dfs(int index, int depth) {
	d[depth]++;
	if (d[depth] > num) {
		num = d[depth];
		dmax = depth;
	}
	for (int i = 0; i < v[index].size(); i++)
		dfs(v[index][i], depth + 1);
}
int main() {
	int n, m, id, k, t;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			v[id].push_back(t);
		}
	}
	dfs(1, 1);
	printf("%d %d", num, dmax);
	return 0;
}
