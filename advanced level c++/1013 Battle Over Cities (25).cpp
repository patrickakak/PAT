#include <iostream>
#include <algorithm>
using namespace std;
int n, e[1010][1010];
bool visit[1010];
void dfs(int cid) {
	visit[cid] = true;
	for (int i = 1; i <= n; i++)
		if (!visit[i] && e[cid][i] == 1) dfs(i);
}
int main() {
	int m, k, a, b;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	for (int i = 0; i < k; i++) {
		fill(visit, visit + 1010, false);
		scanf("%d", &a);
		int cnt = 0;
		visit[a] = true;
		for (int j = 1; j <= n; j++)
			if (!visit[j]) {
				dfs(j);
				cnt++;
			}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
