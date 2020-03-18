#include <iostream>
using namespace std;
struct node {
	string s;
	int l, r;
} a[100];
string inOrder(int root) {
	if (root == -1) return "";
	if (a[root].l == -1 && a[root].r == -1) return a[root].s;
	else return "(" + inOrder(a[root].l) + a[root].s + inOrder(a[root].r) + ")";
}
int main() {
	int h[100] = {0}, n, root = 1;
	cin >> n;
	for (int i  = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].l >> a[i].r;
		if (a[i].l != -1) h[a[i].l] = 1;
		if (a[i].r != -1) h[a[i].r] = 1;
	}
	while (root <= n && h[root] == 1) root++;
	string ans = inOrder(root);
	if (ans[0] == '(') ans = ans.substr(1, ans.size()-2);
	printf("%s", ans.c_str());
	return 0;
}
