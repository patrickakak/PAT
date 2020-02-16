#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int val;
	struct node *left, *right;
};
node *ll(node *tree) {
	node *tmp = tree->right;
	tree->right = tmp->left;
	tmp->left = tree;
	return tmp;
}
node *rr(node *tree) {
	node *tmp = tree->left;
	tree->left = tmp->right;
	tmp->right = tree;
	return tmp;
}
node *lr(node *tree) {
	tree->left = ll(tree->left);
	return rr(tree);
}
node *rl(node *tree) {
	tree->right = rr(tree->right);
	return ll(tree);
}
int getHeight(node *tree) {
	if (tree == NULL) return 0;
	int l = getHeight(tree->left);
	int r = getHeight(tree->right);
	return max(l, r) + 1;
}
node *insert(node *tree, int val) {
	if (tree == NULL) {
		tree = new node();
		tree->val = val;
	} else if (tree->val > val) {
		tree->left = insert(tree->left, val);
		int l = getHeight(tree->left), r = getHeight(tree->right);
		if (l - r >= 2) {
			if (val < tree->left->val) tree = rr(tree);
			else tree = lr(tree);
		}
	} else {
		tree->right = insert(tree->right, val);
		int l = getHeight(tree->left), r = getHeight(tree->right);
		if (r - l >= 2) {
			if (val > tree->right->val) tree = ll(tree);
			else tree = rl(tree);
		}
	}
	return tree;
}
int isComplete = 1, after = 0;
vector<int> levelOrder(node *tree) {
	vector<int> v;
	queue<node *> queue;
	queue.push(tree);
	while (!queue.empty()) {
		node *tmp = queue.front();
		queue.pop();
		v.push_back(tmp->val);
		if (tmp->left != NULL) {
			if (after) isComplete = 0;
			queue.push(tmp->left);
		} else after = 1;
		if (tmp->right != NULL) {
			if (after) isComplete = 0;
			queue.push(tmp->right);
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
