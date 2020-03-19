#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, l, m, k;
struct node {
	int id, layer;
};
vector<vector<int>> v;
int bfs(node t) {
	bool inq[1010] = {false};
	queue<node> q;
	q.push(t);
	inq[t.id] = true;
	int cnt = 0;
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		for (int i = 0; i < v[top.id].size(); i++) {
			int nextid = v[top.id][i];
			if (!inq[nextid] && top.layer < l) {
				q.push({nextid, top.layer+1});
				inq[nextid] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d", &n, &l);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			v[tmp].push_back(i);
		}
	}
	scanf("%d", &k);
	int tid;
	for (int i = 0; i < k; i++) {
		scanf("%d", &tid);
		printf("%d\n", bfs({tid, 0}));
	}
	return 0;
}
