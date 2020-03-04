#include <iostream>
#include <vector>
using namespace std;
struct node {
	string s;
	int l, r;
};
vector<node> v(25);
int h[25];
void dfs(int root) {
	if (root == -1) return;
	int cnt = (v[root].l == -1) + (v[root].r == -1);
	printf("(");
	if (cnt == 1) cout << v[root].s;
	dfs(v[root].l);
	dfs(v[root].r);
	if (cnt != 1) cout << v[root].s;
	printf(")");
}
int main() {
	int n, root = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i].s >> v[i].l >> v[i].r;
		if (v[i].l != -1) h[v[i].l] = 1;
		if (v[i].r != -1) h[v[i].r] = 1;
	}
	while (root <= n && h[root] == 1) root++;
	dfs(root);
	return 0;
}
