#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
struct node {
	int val;
	node *l, *r;
};
node *build(node *r, int v) {
	if (r == NULL) {
		r = new node();
		r->val = v;
		r->l = r->r = NULL;
	} else if (abs(v) < abs(r->val)) r->l = build(r->l, v);
	else r->r = build(r->r, v);
	return r;
}
bool judge1(node *r) {
	if (r == NULL) return true;
	if (r->val < 0) {
		if (r->l && r->l->val < 0) return false;
		if (r->r && r->r->val < 0) return false;
	}
	return judge1(r->l) && judge1(r->r);
}
int getNum(node *root) {
	if (root == NULL) return 1;
	int l = getNum(root->l);
	int r = getNum(root->r);
	return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *r) {
	if (r == NULL) return true;
	if (getNum(r->l) != getNum(r->r)) return false;
	return judge2(r->l) && judge2(r->r);
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
