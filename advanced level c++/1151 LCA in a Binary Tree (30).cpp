#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> pos;
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int u, int v) {
	if (inl > inr) return;
	int inRoot = pos[pre[preRoot]], uIn = pos[u], vIn = pos[v];
	if (uIn < inRoot && vIn < inRoot)
		lca(inl, inRoot - 1, preRoot + 1, u, v);
	else if ((uIn < inRoot && vIn > inRoot) || (uIn > inRoot && vIn < inRoot))
		printf("LCA of %d and %d is %d.\n", u, v, in[inRoot]);
	else if (uIn > inRoot && vIn > inRoot)
		lca(inRoot + 1, inr, preRoot + 1 + (inRoot - inl), u, v);
	else if (uIn == inRoot)
		printf("%d is an ancestor of %d.\n", u, v);
	else if (vIn == inRoot)
		printf("%d is an ancestor of %d.\n", v, u);
}
int main() {
	int m, n, u, v;
	scanf("%d %d", &m, &n);
	in.resize(n + 1), pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
		pos[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
	while (m--) {
		scanf("%d %d", &u, &v);
		if (pos[u] == 0 && pos[v] == 0)
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if (pos[u] == 0 || pos[v] == 0)
			printf("ERROR: %d is not found.\n", pos[u] == 0 ? u : v);
		else lca(1, n, 1, u, v);
	}
	return 0;
}
