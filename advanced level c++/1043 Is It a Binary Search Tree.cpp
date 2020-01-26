/**
 * Sample input1:
 * 7
 * 8 6 5 7 10 8 11
 * Sample output1:
 * YES
 * 5 7 6 8 11 10 8
 * ---------------
 * Sample input2:
 * 7
 * 8 10 11 8 6 7 5
 * Sample output2:
 * YES
 * 11 8 10 7 5 6 8
 * ---------------
 * Sample input3:
 * 7
 * 8 6 8 5 10 9 11
 * Sample output3:
 * NO
 */
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int data;
	node *left, *right;
};

void insert(node* &root, int data)
{
	if (!root) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return ;
	}
	if (data < root->data) insert(root->left, data);
	else insert(root->right, data);
}

void preOrder(node *root, vector<int> &vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

void preOrderMirror(node *root, vector<int> &vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right, vi);
	preOrderMirror(root->left, vi);
}

void postOrder(node *root, vector<int> &vi)
{
	if (root == NULL) return;
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

void postOrderMirror(node *root, vector<int> &vi)
{
	if (root == NULL) return;
	postOrderMirror(root->right, vi);
	postOrderMirror(root->left, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, data;
	node *root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	postOrder(root, post);
	postOrderMirror(root, postM);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < (int)post.size(); i++) {
			printf("%d", post[i]);
			if (i < (int)post.size()-1) printf(" ");
		}
	} else if (origin == preM) {
		printf("YES\n");
		for (int i = 0; i < (int)postM.size(); i++) {
			printf("%d", postM[i]);
			if (i < (int)postM.size()-1) printf(" ");
		}
	} else
		printf("NO\n");

	return 0;
}

