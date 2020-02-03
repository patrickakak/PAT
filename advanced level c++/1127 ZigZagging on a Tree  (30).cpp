#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post, res[35];
int n, tree[35][2], root;
struct node {
	int index, depth;
};
void dfs(int &index, int inl, int inr, int postl, int postr) {
	if (inl > inr) return;
	index = postr;
	int i = 0;
	while (in[i] != post[postr]) i++;
	dfs(tree[index][0], inl, i - 1, postl, postl + (i - inl) - 1);
	dfs(tree[index][1], i + 1, inr, postl + (i - inl), postr - 1);
}
void bfs() {
	queue<node> q;
	q.push(node{root, 0});
	while (!q.empty()) {
		node tmp = q.front();
		q.pop();
		res[tmp.depth].push_back(post[tmp.index]);
		if (tree[tmp.index][0] != 0)
			q.push(node{tree[tmp.index][0], tmp.depth + 1});
		if (tree[tmp.index][1] != 0)
			q.push(node{tree[tmp.index][1], tmp.depth + 1});
	}
}
int main() {
	cin >> n;
	in.resize(n + 1), post.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> in[i];
	for (int i = 1; i <= n; i++) cin >> post[i];
	dfs(root, 1, n, 1, n);
	bfs();
	printf("%d", res[0][0]);
	for (int i = 1; i < 35; i++)
		if (i % 2 == 1)
			for (int j = 0; j < res[i].size(); j++)
				printf(" %d", res[i][j]);
		else
			for (int j = res[i].size() - 1; j >= 0; j--)
				printf(" %d", res[i][j]);
	return 0;
}
