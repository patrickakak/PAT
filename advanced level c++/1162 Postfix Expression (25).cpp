#include <iostream>
using namespace std;
struct node {
	string s;
	int l, r;
} a[25];
int h[25];
void dfs(int root) {
	if (root == -1) return;
	int cnt = (a[root].l == -1) + (a[root].r == -1);
	printf("(");
	if (cnt == 1) cout << a[root].s;
	dfs(a[root].l);
	dfs(a[root].r);
	if (cnt != 1) cout << a[root].s;
	printf(")");
}
int main() {
	int n, root = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].l >> a[i].r;
		if (a[i].l != -1) h[a[i].l] = 1;
		if (a[i].r != -1) h[a[i].r] = 1;
	}
	while (root <= n && h[root] == 1) root++;
	dfs(root);
	return 0;
}
