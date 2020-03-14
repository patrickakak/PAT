#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> pos;
vector<int> in, pre;
void lca(int prel, int prer, int inl, int inr, int u, int v) {
	if (inl > inr) return;
	int rin = pos[pre[prel]], uin = pos[u], vin = pos[v];
	if (uin < rin && vin < rin)
		lca(prel+1, prel+(rin-inl)-1, inl, rin-1, u, v);
	else if ((uin < rin && vin > rin) || (uin > rin && vin < rin))
		printf("LCA of %d and %d is %d.\n", u, v, in[rin]);
	else if (uin > rin && vin > rin)
		lca(prel+1+(rin-inl), prer, rin+1, inr, u, v);
	else printf("%d is an ancestor of %d.\n", in[rin], uin == rin ? v : u);
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
		else lca(1, n, 1, n, u, v);
	}
	return 0;
}
