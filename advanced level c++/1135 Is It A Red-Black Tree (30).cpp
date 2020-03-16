#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
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
bool judge1(node *rt) {
	if (rt == NULL) return true;
	if (rt->key < 0) {
		if (rt->l && rt->l->key < 0) return false;
		if (rt->r && rt->r->key < 0) return false;
	}
	return judge1(rt->l) && judge1(rt->r);
}
int getNum(node *rt) {
	if (rt == NULL) return 1;
	int l = getNum(rt->l);
	int r = getNum(rt->r);
	return rt->key > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *rt) {
	if (rt == NULL) return true;
	if (getNum(rt->l) != getNum(rt->r)) return false;
	return judge2(rt->l) && judge2(rt->r);
}
int main() {
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		a.resize(n);
		node *root = NULL;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
			root = build(root, a[j]);
		}
		if (a[0] < 0 || judge1(root) == false || judge2(root) == false) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
