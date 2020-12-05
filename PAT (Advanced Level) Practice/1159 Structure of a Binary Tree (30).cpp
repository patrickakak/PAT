#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
	int key, level;
	node *p, *l, *r;
};
bool is_full = true;
unordered_map<int, node*> mp;
vector<int> in, post;
node *build(int inl, int inr, int postl, int postr) {
	if (inl > inr || postl > postr) return nullptr;
	node *root = new node{post[postr], 1, NULL, NULL, NULL};
	mp[root->key] = root;
	int i = inl;
	while (i <= inr && in[i] != root->key) i++;
	root->l = build(inl, i-1, postl, postl+i-inl-1);
	root->r = build(i+1, inr, postl+i-inl, postr-1);
	if (root->l) root->l->p = root;
	if (root->r) root->r->p = root;
	return root;
}
void dfs(node *root) {
	if (!root) return;
	if (root->p) root->level = root->p->level + 1;
	if (root->l && !root->r) is_full = false;
	if (!root->l && root->r) is_full = false;
	dfs(root->l);
	dfs(root->r);
}
int main() {
	int n, m;
	scanf("%d", &n);
	in.resize(n), post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	node *root = build(0, n-1, 0, n-1);
	dfs(root);
	scanf("%d\n", &m);
	while (m--) {
		bool flag;
		int a, b;
		string s;
		getline(cin, s);
		if (s.find("root") != string::npos) {
			sscanf(s.c_str(), "%d is the root", &a);
			flag = (a == root->key);
		} else if (s.find("siblings") != string::npos) {
			sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
			flag = (mp[a]->p == mp[b]->p);
		} else if (s.find("parent") != string::npos) {
			sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
			flag = (mp[b]->p == mp[a]);
		} else if (s.find("left") != string::npos) {
			sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
			flag = (mp[b]->l == mp[a]);
		} else if (s.find("right") != string::npos) {
			sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
			flag = (mp[b]->r == mp[a]);
		} else if (s.find("level") != string::npos) {
			sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
			flag = (mp[a]->level == mp[b]->level);
		} else flag = is_full;
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}
