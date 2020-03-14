#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int l, r;
};
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
void inOrder(int root) {
	if (root == -1) return;
	inOrder(tree[root].l);
	in.push_back(root);
	inOrder(tree[root].r);
}
int main() {
	int n, root = 0;
	cin >> n;
	string l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		if (l != "-") {
			tree[i].r = stoi(l);
			h[stoi(l)] = 1;
		} else tree[i].r = -1;
		if (r != "-") {
			tree[i].l = stoi(r);
			h[stoi(r)] = 1;
		} else tree[i].l = -1;
	}
	while (h[root] == 1) root++;
	bfs(root);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", level[i]);
	}
	printf("\n");
	inOrder(root);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", in[i]);
	}
	return 0;
}
