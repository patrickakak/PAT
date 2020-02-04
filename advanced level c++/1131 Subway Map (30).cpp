#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTrans, src, dest;
unordered_map<int, int> line;
vector<int> path, tmpPath;
int transCnt(vector<int> a) {
	int cnt = -1, preLine = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i-1] * 10000 + a[i]] != preLine) cnt++;
		preLine = line[a[i-1] * 10000 + a[i]];
	}
	return cnt;
}
void dfs(int node, int cnt) {
	if (node == dest && (cnt < minCnt || (cnt == minCnt && transCnt(tmpPath) < minTrans))) {
		minCnt = cnt;
		minTrans = transCnt(tmpPath);
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
			line[pre * 10000 + tmp] = line[tmp * 10000 + pre] = i + 1;
			pre = tmp;
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &src, &dest);
		minCnt = minTrans = 0x3ffffff;
		tmpPath.clear();
		tmpPath.push_back(src);
		visit[src] = 1;
		dfs(src, 0);
		visit[src] = 0;
		printf("%d\n", minCnt);
		int preLine = 0, preTrans = src;
		for (int i = 1; i < path.size(); i++)
			if (line[path[i-1] * 10000 + path[i]] != preLine) {
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, path[i-1]);
				preLine = line[path[i-1] * 10000 + path[i]];
				preTrans = path[i-1];
			}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, dest);
	}
	return 0;
}
