#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int val;
	struct node *left, *right;
};
node *ll(node *root) {
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node *rr(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node *lr(node *root) {
	root->left = rr(root->left);
	return ll(root);
}
node *rl(node *root) {
	root->right = ll(root->right);
	return rr(root);
}
int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
	if (root == NULL) {
		root = new node();
		*root = node{val, NULL, NULL};
	} else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
			root = val < root->left->val ? ll(root) : lr(root);
	} else {
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
			root = val > root->right->val ? rr(root) : rl(root);
	}
	return root;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(node *tree) {
	vector<int> v;
	queue<node *> q;
	q.push(tree);
	while (!q.empty()) {
		node *tmp = q.front();
		q.pop();
		v.push_back(tmp->val);
		if (tmp->left != NULL) {
			if (after) isComplete = 0;
			q.push(tmp->left);
		} else after = 1;
		if (tmp->right != NULL) {
			if (after) isComplete = 0;
			q.push(tmp->right);
		} else after = 1;
	}
	return v;
}
int main() {
	int n, tmp;
	scanf("%d", &n);
	node *tree = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		tree = insert(tree, tmp);
	}
	vector<int> v = levelOrder(tree);
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n%s", isComplete ? "YES" : "NO");
	return 0;
}
