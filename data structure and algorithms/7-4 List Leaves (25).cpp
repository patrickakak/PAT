#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int l, r;
} tree[11];
int h[11];
vector<int> ans;
void levTrav(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (tree[t].l == -1 && tree[t].r == -1) ans.push_back(t);
		if (tree[t].l != -1) q.push(tree[t].l);
		if (tree[t].r != -1) q.push(tree[t].r);
	}
}
int main() {
	int n, root = 0;
	cin >> n;
	string l, r;
	for (int i = 0; i < n; i++) {
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
	while (root < n && h[root] == 1) root++;
	levTrav(root);
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
