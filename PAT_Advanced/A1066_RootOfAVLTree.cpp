/**
 * Sample input1:
 * 5
 * 88 70 61 96 120
 * Sample output1:
 * 70
 * -----------------
 * Sample input2:
 * 7
 * 88 70 61 96 120 90 65
 * Sample output2:
 * 88
 */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node *BT;
struct Node {
	int v, ht;	// height
	BT l, r;	// left, right
} *root;

BT newNode(int v)
{
	BT node = new Node;
	node->v = v;
	node->ht = 1;
	node->l = node->r = NULL;
	return node;
}

int getHeight(BT root)
{
	if (root == NULL) return 0;
	return root->ht;
}

void updateHeight(BT root)
{
	root->ht = max(getHeight(root->l), getHeight(root->r)) + 1;
}

int getBalanceFactor(BT root)
{
	return getHeight(root->l) - getHeight(root->r);
}

void L(BT &root)
{
	BT tmp = root->r;
	root->r = tmp->l;
	tmp->l = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void R(BT &root)
{
	BT tmp = root->l;
	root->l = tmp->r;
	tmp->r = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insert(BT &root, int v)
{
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {
		insert(root->l, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->l) == 1)
				R(root);
			else if (getBalanceFactor(root->l) == -1) {
				L(root->l);
				R(root);
			}
		}
	} else {
		insert(root->r, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->r) == -1)
				L(root);
			else if (getBalanceFactor(root->r) == 1) {
				R(root->r);
				L(root);
			}
		}
	}
}

BT Create(int data[], int n)
{
	BT root = NULL;
	for (int i = 0; i < n; i++)
		insert(root, data[i]);
	return root;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, v;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->v);

	return 0;
}



