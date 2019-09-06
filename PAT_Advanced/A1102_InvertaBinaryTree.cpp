/**
 * Sample input:
 * 8
 * 1 -
 * - -
 * 0 -
 * 2 7
 * - -
 * - -
 * 5 -
 * 4 6
 * ---------------
 * Sample output:
 * 3 7 2 6 4 0 5 1
 * 6 5 7 4 3 2 0 1
 */
#include <cstdio>
#include <queue>
using namespace std;

#define maxn 110
struct Node {
	int l, r;
} node[maxn];
bool notRoot[maxn] = {false};
int n, num = 0;

int cntNode(int i)
{
	if (i == -1) return 0;
	return 1 + cntNode(node[i].l) + cntNode(node[i].r);
}

void invertBT(int rt)
{
	if (rt == -1) return;
	invertBT(node[rt].l);
	invertBT(node[rt].r);
	swap(node[rt].l, node[rt].r);
}

void inOrder(int rt)
{
	if (rt == -1) return;
	inOrder(node[rt].l);
	printf("%d", rt);
	num++;
	if (num < n) printf(" ");
	else printf("\n");
	inOrder(node[rt].r);
}

void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", now);
		num++;
		if (num < n) printf(" ");
		else printf("\n");
		if (node[now].l != -1) q.push(node[now].l);
		if (node[now].r != -1) q.push(node[now].r);
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	char left, right;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &left, &right);
		if (left == '-') node[i].l = -1;
		else node[i].l = left - '0';
		if (right == '-') node[i].r = -1;
		else node[i].r = right - '0';
	}
	int root;
	for (root = 0; root < n; root++)
		if (cntNode(root) == n) break;

	invertBT(root);
	BFS(root);
	num = 0;
	inOrder(root);

	return 0;
}

