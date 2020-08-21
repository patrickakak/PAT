#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct qnode {
	int poptime, endtime;
	queue<int> q;
};
int main() {
	int n, m, k, q, idx = 1, query;
	cin >> n >> m >> k >> q;
	vector<qnode> p(n+1);
	vector<int> tm(k+1), ans(k+1), sorry(k+1);
	for (int i = 1; i <= k; i++) scanf("%d", &tm[i]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (idx <= k) {
				p[j].q.push(tm[idx]);
				if (p[j].endtime >= (17-8)*60) sorry[idx] = 1;
				p[j].endtime += tm[idx];
				if (i == 1) p[j].poptime = p[j].endtime;
				ans[idx] = p[j].endtime;
				idx++;
			}
	while (idx <= k) {
		int tmpmin = p[1].poptime, j = 1;
		for (int i = 2; i <= n; i++)
			if (tmpmin > p[i].poptime) {
				tmpmin = p[i].poptime;
				j = i;
			}
		p[j].q.pop();
		p[j].q.push(tm[idx]);
		p[j].poptime += p[j].q.front();
		if (p[j].endtime >= (17-8)*60) sorry[idx] = 1;
		p[j].endtime += tm[idx];
		ans[idx] = p[j].endtime;
		idx++;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &query);
		if (sorry[query] == 1) printf("Sorry\n");
		else printf("%02d:%02d\n", (ans[query]+8*60)/60, (ans[query]+8*60)%60);
	}
	return 0;
}
