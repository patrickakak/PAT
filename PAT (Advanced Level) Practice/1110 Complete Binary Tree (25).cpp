#include <iostream>
using namespace std;
struct node{
	int l, r;
} tree[100];
int maxn = -1, ans;
void dfs(int root, int idx) {
	if (idx > maxn) {
		maxn = idx;
		ans = root;
	}
	if (tree[root].l != -1) dfs(tree[root].l, 2*idx);
	if (tree[root].r != -1) dfs(tree[root].r, 2*idx+1);
}
int main() {
	int n, root = 0, h[100] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		string l, r;
		cin >> l >> r;
		if (l == "-") tree[i].l = -1;
		else {
			tree[i].l = stoi(l);
			h[stoi(l)] = 1;
		}
		if (r == "-") tree[i].r = -1;
		else {
			tree[i].r = stoi(r);
			h[stoi(r)] = 1;
		}
	}
	while (h[root] != 0) root++;
	dfs(root, 1);
	if (maxn == n) printf("YES %d", ans);
	else printf("NO %d", root);
	return 0;
}
