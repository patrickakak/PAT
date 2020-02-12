#include <iostream>
#include <vector>
using namespace std;
struct node {
	int v;
	node *l, *r;
};
void insert(node *&root, int v) {
	if (root == NULL) {
		node *t = new node;
		*t = node{v, NULL, NULL};
		root = t;
		return;
	}
	if (v < root->v) insert(root->l, v);
	else insert(root->r, v);
}
void preOrder(node *root, vector<int> &vec) {
	if (root == NULL) return;
	vec.push_back(root->v);
	preOrder(root->l, vec);
	preOrder(root->r, vec);
}
int main() {
	int n, l, t;
	cin >> n;
	while (n) {
		node *root = NULL;
		vector<int> pre;
		cin >> l;
		for (int i = 0; i < n; i++) {
			cin >> t;
			insert(root, t);
		}
		preOrder(root, pre);
		while (l--) {
			node *tmpRoot = NULL;
			for (int i = 0; i < n; i++) {
				cin >> t;
				insert(tmpRoot, t);
			}
			vector<int> tmpPre;
			preOrder(tmpRoot, tmpPre);
			if (tmpPre == pre) printf("Yes\n");
			else printf("No\n");
		}
		cin >> n;
	}
	return 0;
}
