#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 0x2fffffff;
int n, m, e[110][110], ind[110], earliest[110];
int main() {
	fill(e[0], e[0] + 110 * 110, inf);
	cin >> n >> m;
	int start, end, l, cnt = 0;
	while (m--) {
		cin >> start >> end >> l;
		e[start][end] = l;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (e[i][j] != inf) ind[j]++;
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < n; i++)
			if (e[v][i] != inf) {
				if (earliest[i] < earliest[v] + e[v][i]) earliest[i] = earliest[v] + e[v][i];
				if (--ind[i] == 0) q.push(i);
			}
	}
	if (cnt != n) printf("Impossible");
	else printf("%d", *max_element(earliest, earliest+n));
	return 0;
}
