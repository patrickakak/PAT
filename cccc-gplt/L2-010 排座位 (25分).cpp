#include <iostream>
using namespace std;
int e[110][110], father[110];
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
	if (faA != faB) father[faA] = faB;
}
int main() {
	int n, m, k, a, b, r;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &r);
		e[a][b] = e[b][a] = r;
		if (r == 1) Union(a, b);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a, &b);
		if (find(a) == find(b)) {
			if (e[a][b] != -1) printf("No problem\n");
			else printf("OK but...\n");
		} else {
			if (e[a][b] != -1) printf("OK\n");
			else printf("No way\n");
		}
	}
	return 0;
}
