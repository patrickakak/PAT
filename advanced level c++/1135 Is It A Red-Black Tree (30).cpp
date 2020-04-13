#include <iostream>
using namespace std;
struct node {
	int key;
	node *l, *r;
};
node *build(node *rt, int v) {
	if (rt == NULL) {
		rt = new node();
		*rt = {v, NULL, NULL};
	} else if (abs(v) < abs(rt->key)) rt->l = build(rt->l, v);
	else rt->r = build(rt->r, v);
	return rt;
}
bool f1(node *rt) {
	if (rt == NULL) return true;
	if (rt->key < 0) {
		if (rt->l && rt->l->key < 0) return false;
		if (rt->r && rt->r->key < 0) return false;
	}
	return f1(rt->l) && f1(rt->r);
}
int cnt(node *rt) {
	if (rt == NULL) return 1;
	int l = cnt(rt->l);
	int r = cnt(rt->r);
	return rt->key > 0 ? max(l, r) + 1 : max(l, r);
}
bool f2(node *rt) {
	if (rt == NULL) return true;
	if (cnt(rt->l) != cnt(rt->r)) return false;
	return f2(rt->l) && f2(rt->r);
}
int main() {
	int k, n, v;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		node *root = NULL;
		for (int j = 0; j < n; j++) {
			scanf("%d", &v);
			root = build(root, v);
		}
		if (root->key < 0 || f1(root) == false || f2(root) == false) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
