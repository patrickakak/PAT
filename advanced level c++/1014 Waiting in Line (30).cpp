#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
	int poptime, endtime;
	queue<int> q;
};
int main() {
	int n, m, k, q, index = 1;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vector<int> time(k + 1), res(k + 1);
	for (int i = 1; i <= k; i++) scanf("%d", &time[i]);
	vector<node> win(n + 1);
	vector<bool> sorry(k + 1, false);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (index <= k) {
				win[j].q.push(time[index]);
				if (win[j].endtime >= 540) sorry[index] = true;
				win[j].endtime += time[index];
				if (i == 1) win[j].poptime = win[j].endtime;
				res[index] = win[j].endtime;
				index++;
			}
	while (index <= k) {
		int tmpmin = win[1].poptime, tmpwin = 1;
		for (int i = 2; i <= n; i++)
			if (win[i].poptime < tmpmin) {
				tmpwin = i;
				tmpmin = win[i].poptime;
			}
		win[tmpwin].q.pop();
		win[tmpwin].q.push(time[index]);
		win[tmpwin].poptime +=  win[tmpwin].q.front();
		if (win[tmpwin].endtime >= 540) sorry[index] = true;
		win[tmpwin].endtime += time[index];
		res[index] = win[tmpwin].endtime;
		index++;
	}
	for (int i = 1; i <= q; i++) {
		int query, minute;
		scanf("%d", &query);
		minute = res[query];
		if (sorry[query] == true) printf("Sorry\n");
		else printf("%02d:%02d\n", (minute + 8*60) / 60, (minute + 8*60) % 60);
	}
	return 0;
}
