#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 0x2fffffff;
int n, key[1010], ind[1010], e[1010][1010];
struct cmp {
	bool operator () (int a, int b) {
		return key[a] > key[b];
	}
};
int main() {
	fill(e[0], e[0] + 1010 * 1010, inf);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &key[i]);
		if (key[i] < 0) continue;
		int pos = key[i] % n;
		if (pos != i)
			for (int j = pos; j != i; j = (j+1)%n)
				e[j][i] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (e[i][j] == 1) ind[j]++;
	priority_queue<int, vector<int>, cmp> q;
	for (int i = 0; i < n; i++)
		if (key[i] >= 0 && ind[i] == 0) q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int t = q.top();
		ans.push_back(key[t]);
		q.pop();
		for (int i = 0; i < n; i++)
			if (e[t][i] == 1) {
				if (--ind[i] == 0) q.push(i);
			}
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
