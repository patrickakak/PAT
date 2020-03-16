#include <iostream>
#include <vector>
using namespace std;
struct node {
	int key;
	node *l, *r;
} *root;
vector<int> in, post, d[30];
int n, dmax = 0;
void dfs(node *rt, int level) {
	if (rt == NULL) return;
	if (dmax < level) dmax = level;
	d[level].push_back(rt->key);
	if (rt->l) dfs(rt->l, level + 1);
	if (rt->r) dfs(rt->r, level + 1);
}
node *build(int inl, int inr, int postl, int postr) {
	if (inl > inr) return NULL;
	node *t = new(node);
	t->key = post[postr];
	int i = inl;
	while (i <= inr && in[i] != post[postr]) i++;
	t->l = build(inl, i-1, postl, postl+i-inl-1);
	t->r = build(i+1, inr, postl+i-inl, postr-1);
	return t;
}
int main() {
	cin >> n;
	in.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	root = build(0, n-1, 0, n-1);
	dfs(root, 0);
	printf("%d", d[0][0]);
	for (int i = 1; i <= dmax; i++)
		if (i % 2 == 0)
			for (int j = d[i].size()-1; j >= 0; j--) printf(" %d", d[i][j]);
		else
			for (int j = 0; j < d[i].size(); j++) printf(" %d", d[i][j]);
	return 0;
}
