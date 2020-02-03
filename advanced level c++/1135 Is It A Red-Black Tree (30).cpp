#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
struct node {
	int val;
	node *l, *r;
};
node *build(node *root, int v) {
	if (root == NULL) {
		root = new node();
		root->val = v;
		root->l = root->r = NULL;
	} else if (abs(v) < abs(root->val)) root->l = build(root->l, v);
	else root->r = build(root->r, v);
	return root;
}
bool judge1(node *root) {
	if (root == NULL) return true;
	if (root->val < 0) {
		if (root->l != NULL && root->l->val < 0) return false;
		if (root->r != NULL && root->r->val < 0) return false;
	}
	return judge1(root->l) && judge1(root->r);
}
int getNum(node *root) {
	if (root == NULL) return 0;
	int l = getNum(root->l);
	int r = getNum(root->r);
	return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
	if (root == NULL) return true;
	int l = getNum(root->l);
	int r = getNum(root->r);
	if (l != r) return false;
	return judge2(root->l) && judge2(root->r);
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
