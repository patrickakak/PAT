#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, src, dest;
unordered_map<int, int> line;
vector<int> path, tmpPath;
int transferCnt(vector<int> a) {
	int cnt = -1, preLine = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
		preLine = line[a[i-1]*10000+a[i]];
	}
	return cnt;
}
void dfs(int node, int cnt) {
	if (node == dest && (cnt < minCnt || (cnt == minCnt && transferCnt(tmpPath) < minTransfer))) {
		minCnt = cnt;
		minTransfer = transferCnt(tmpPath);
		path = tmpPath;
	}
	if (node == dest) return;
	for (int i = 0; i < v[node].size(); i++)
		if (visit[v[node][i]] == 0) {
			visit[v[node][i]] = 1;
			tmpPath.push_back(v[node][i]);
			dfs(v[node][i], cnt + 1);
			visit[v[node][i]] = 0;
			tmpPath.pop_back();
		}
}
int main() {
	int n, m, k, pre, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &m, &pre);
		for (int j = 1; j < m; j++) {
			scanf("%d", &tmp);
			v[pre].push_back(tmp);
			v[tmp].push_back(pre);
			line[pre*10000+tmp] = line[tmp*10000+pre] = i + 1;
			pre = tmp;
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &src, &dest);
		minCnt = 99999, minTransfer = 99999;
		tmpPath.clear();
		tmpPath.push_back(src);
		visit[src] = 1;
		dfs(src, 0);
		visit[src] = 0;
		printf("%d\n", minCnt);
		int preLine = 0, preTransfer = src;
		for (int j = 1; j < path.size(); j++)
			if (line[path[j-1]*10000+path[j]] != preLine) {
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
				preLine = line[path[j-1]*10000+path[j]];
				preTransfer = path[j-1];
			}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, dest);
	}
	return 0;
}
