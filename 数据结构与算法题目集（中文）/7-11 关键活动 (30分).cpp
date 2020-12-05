#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 0x2fffffff;
int n, m, e[110][110], ind[110], earliest[110], outd[110], latest[110];
int main() {
	fill(e[0], e[0] + 110 * 110, inf);
	fill(latest, latest + 110, inf);
	cin >> n >> m;
	int start, end, l, cnt = 0;
	while (m--) {
		cin >> start >> end >> l;
		e[start][end] = l;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (e[i][j] != inf) {
				ind[j]++;
				outd[i]++;
			}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cnt++;
		for (int i = 1; i <= n; i++)
			if (e[v][i] != inf) {
				if (earliest[i] < earliest[v] + e[v][i]) earliest[i] = earliest[v] + e[v][i];
				if (--ind[i] == 0) q.push(i);
			}
	}
	if (cnt != n) {
		printf("0"); return 0;
	}
	int maxn = *max_element(earliest+1, earliest+1+n);
	printf("%d\n", maxn);
	for (int i = 1; i <= n; i++)
		if (outd[i] == 0) {
			latest[i] = maxn;
			q.push(i);
		}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
			if (e[i][v] != inf) {
				if (latest[i] > latest[v] - e[i][v]) latest[i] = latest[v] - e[i][v];
				if (--outd[i] == 0) q.push(i);
			}
	}
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--)
			if (e[i][j] != inf && latest[j] - earliest[i] - e[i][j] == 0)
				printf("%d->%d\n", i, j);
	return 0;
}
