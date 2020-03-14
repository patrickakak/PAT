#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> pos;
vector<int> pre, in;
void lca(int prel, int prer, int inl, int inr, int u, int v) {
	if (inl > inr) return;
	int ain = pos[pre[prel]], uin = pos[u], vin = pos[v];
	if (uin < ain && vin < ain)
		lca(prel+1, prel+(ain-inl)-1, inl, ain-1, u, v);
	else if ((uin < ain && vin > ain) || (uin > ain && vin < ain))
		printf("LCA of %d and %d is %d.\n", u, v, in[ain]);
	else if (uin > ain && vin > ain)
		lca(prel+1+(ain-inl), prer, ain+1, inr, u, v);
	else printf("%d is an ancestor of %d.\n", in[ain], uin == ain ? v : u);
}
int main() {
	int m, n, u, v;
	scanf("%d %d", &m, &n);
	pre.resize(n + 1), in.resize(n + 1);
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
