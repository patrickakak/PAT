#include <iostream>
using namespace std;
struct node {
	string data;
	int l, r;
} a[100];
string dfs(int rt) {
	if (a[rt].l == -1 && a[rt].r == -1) return a[rt].data;
	if (a[rt].l == -1 && a[rt].r != -1) return "(" +  a[rt].data + dfs(a[rt].r) + ")";
	if (a[rt].l != -1 && a[rt].r != -1) return "(" +  dfs(a[rt].l) + a[rt].data + dfs(a[rt].r) + ")";
}
int main() {
	int h[100] = {0}, n, rt = 1;
	cin >> n;
	for (int i  = 1; i <= n; i++) {
		cin >> a[i].data >> a[i].l >> a[i].r;
		if (a[i].l != -1) h[a[i].l] = 1;
		if (a[i].r != -1) h[a[i].r] = 1;
	}
	while (h[rt] == 1) rt++;
	string ans = dfs(rt);
	if (ans[0] == '(') ans = ans.substr(1, ans.size()-2);
	cout << ans;
	return 0;
}
