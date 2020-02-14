#include <iostream>
using namespace std;
const int inf = 0x3fffffff;
int n, m, d[110][110];
int main() {
	fill(d[0], d[0]+110*110, inf);
	cin >> n >> m;
	int a, b, w, id, mindist = inf;
	while (m--) {
		cin >> a >> b >> w;
		d[a][b] = d[b][a] = w;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j && d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
	for (int i = 1; i <= n; i++) {
		int maxdist = 0;
		for (int j = 1; j <= n; j++)
			if (i != j && d[i][j] > maxdist) maxdist = d[i][j];
		if (maxdist == inf) {
			printf("0");
			return 0;
		}
		if (mindist > maxdist) {
			mindist = maxdist;
			id = i;
		}
	}
	printf("%d %d", id, mindist);
	return 0;
}
