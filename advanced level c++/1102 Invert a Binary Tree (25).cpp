#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node { int l, r; };
vector<node> tree(10);
vector<int> h(10), level, in;
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		level.push_back(t);
		if (tree[t].l != -1) q.push(tree[t].l);
		if (tree[t].r != -1) q.push(tree[t].r);
	}
}
void inorder(int root) {
	if (root == -1) return;
	inorder(tree[root].l);
	in.push_back(root);
	inorder(tree[root].r);
}
int main() {
	int n, root = 0;
	cin >> n;
	char l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (l != '-') {
			tree[i].r = l - '0';
			h[l - '0'] = 1;
		} else tree[i].r = -1;
		if (r != '-') {
			tree[i].l = r - '0';
			h[r - '0'] = 1;
		} else tree[i].l = -1;
	}
	while (h[root] == 1) root++;
	bfs(root);
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << ' ';
		cout << level[i];
	}
	cout << endl;
	inorder(root);
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << ' ';
		cout << in[i];
	}
	return 0;
}
