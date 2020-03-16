#include <iostream>
#include <vector>
using namespace std;
struct node {
	int v;
	node *l, *r;
};
void insert(node *&rt, int v) {
	if (rt == NULL) {
		rt = new node;
		*rt = {v, NULL, NULL};
		return;
	}
	if (v < rt->v) insert(rt->l, v);
	else insert(rt->r, v);
}
void preOrder(node *rt, vector<int> &vec) {
	if (rt == NULL) return;
	vec.push_back(rt->v);
	preOrder(rt->l, vec);
	preOrder(rt->r, vec);
}
int main() {
	int n, l, t;
	cin >> n;
	while (n) {
		node *root = NULL;
		vector<int> pre;
		scanf("%d", &l);
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			insert(root, t);
		}
		preOrder(root, pre);
		while (l--) {
			node *tmpRoot = NULL;
			for (int i = 0; i < n; i++) {
				scanf("%d", &t);
				insert(tmpRoot, t);
			}
			vector<int> tmpPre;
			preOrder(tmpRoot, tmpPre);
			if (tmpPre == pre) printf("Yes\n");
			else printf("No\n");
		}
		scanf("%d", &n);
	}
	return 0;
}
