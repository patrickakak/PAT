#include <iostream>
using namespace std;
struct node {
	int v;
	node *l, *r;
};
void insert(node *&r, int v) {
	node *t = new(node);
	*t = {v, NULL, NULL};
	if (r == NULL) r = t;
	else if (v <= r->v) insert(r->l, v);
	else insert(r->r, v);
}
int d[1010], dmax = 0;
void dfs(node *r, int depth) {
	d[depth]++;
	if (r->l == NULL && r->r == NULL && dmax < depth) dmax = depth;
	if (r->l) dfs(r->l, depth + 1);
	if (r->r) dfs(r->r, depth + 1);
}
int main() {
	int n, v;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert(root, v);
	}
	dfs(root, 0);
	printf("%d + %d = %d", d[dmax], d[dmax-1], d[dmax] + d[dmax-1]);
	return 0;
}
