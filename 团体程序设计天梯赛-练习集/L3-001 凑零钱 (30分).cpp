#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, flag = 0;
vector<int> v, rest, path;
void dfs(int idx, int sum) {
	if (flag == 1 || sum+rest[idx] < m) return;
	if (idx == n || sum >= m) {
		if (sum == m) {
			flag = 1;
			for (int i = 0; i < path.size(); i++) {
				if (i != 0) printf(" ");
				printf("%d", path[i]);
			}
		}
		return;
	}
	path.push_back(v[idx]);
	dfs(idx + 1, sum + v[idx]);
	path.pop_back();
	dfs(idx + 1, sum);
}
int main() {
	cin >> n >> m;
	v.resize(n), rest.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for (int i = n-1; i >= 0; i--)
		if (i == n-1) rest[i] = v[i];
		else rest[i] = rest[i+1] + v[i];
	dfs(0, 0);
	if (flag == 0) printf("No Solution");
	return 0;
}
