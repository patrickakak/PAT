/**
 * Sample input:
 * 9
 * 1 6
 * 2 3
 * -1 -1
 * -1 4
 * 5 -1
 * -1 -1
 * 7 -1
 * -1 8
 * -1 -1
 * 73 45 11 58 82 25 67 38 42
 * --------------------------
 * Sample output:
 * 58 25 82 11 38 67 45 73 42
 */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct Node {
	int data, left, right;
} node[maxn];
int n, in[maxn], num = 0;

void inOrder(int root)
{
	if (root == -1) return;
	inOrder(node[root].left);
	node[root].data = in[num++];
	inOrder(node[root].right);
}

void BFS(int root)
{
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

int main()
{
	// freopen("tst.txt", "r", stdin);
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



