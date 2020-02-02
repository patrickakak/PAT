#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Node {
	int data, left, right;
} node[maxn];
int n, in[maxn], num = 0;
void inOrder(int root) {
	if (root == -1) return;
	inOrder(node[root].left);
	node[root].data = in[num++];
	inOrder(node[root].right);
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", node[now].data);
		num++;
		if (num < n) printf(" ");
		if (node[now].left != -1) q.push(node[now].left);
		if (node[now].right != -1) q.push(node[now].right);
	}
}
int main() {
	int left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &left, &right);
		node[i].left = left;
		node[i].right = right;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in, in + n);
	inOrder(0);
	BFS(0);
	return 0;
}
