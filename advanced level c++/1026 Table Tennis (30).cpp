#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
struct player {
	int arv, t, is, srv;
} p[10010];
bool cmp1(player &a, player &b) {
	return a.arv < b.arv;
}
bool cmp2(player &a, player &b) {
	return a.srv < b.srv;
}
int vip[110], cnt[110], vis[110], a[2];
queue<int> q[2];
int main() {
	int n, k, m, hh, mm, ss, tid, pos = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p[i].t, &p[i].is);
		p[i].arv = hh*60*60 + mm*60 + ss;
		p[i].t = min(p[i].t*60, 2*60*60);
	}
	sort(p+1, p+n+1, cmp1);
	cin >> k >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tid);
		vip[tid] = 1;
	}
	for (int i = 8*60*60; i < 21*60*60; i++) {
		if (pos<=n && p[pos].arv==i) q[p[pos].is].push(pos), pos++;
		if (!q[0].empty()) a[0] = q[0].front();
		if (!q[1].empty()) a[1] = q[1].front();
		queue<int> v;
		for (int j = 1; j <= k; j++) {
			if (vis[j] && p[vis[j]].srv+p[vis[j]].t==i) vis[j] = 0;
			if (!vis[j] && vip[j]) v.push(j);
		}
		while (!q[1].empty() && !v.empty()) {
			q[1].pop();
			int num = v.front();
			v.pop();
			vis[num] = a[1];
			cnt[num]++;
			p[a[1]].srv = i;
			a[1] = !q[1].empty() ? q[1].front() : 0;
		}
		for (int j = 1; j <= k; j++)
			if (!vis[j]) {
				if (!a[0] && !a[1]) continue;
				int op = 0;
				if (a[1] && (!a[0] || p[a[1]].arv<p[a[0]].arv)) op = 1;
				q[op].pop();
				vis[j] = a[op];
				p[a[op]].srv = i;
				a[op] = !q[op].empty() ? q[op].front() : 0;
				cnt[j]++;
			}
	}
	sort(p+1, p+n+1, cmp2);
	for (int i = 1; i <= n; i++)
		if (p[i].srv != 0)
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p[i].arv/3600, p[i].arv%3600/60, 
					p[i].arv%60, p[i].srv/3600, p[i].srv%3600/60, p[i].srv%60, (int)round((p[i].srv-p[i].arv)/60.0));
	for (int i = 1; i <= k; i++)
		printf("%d%c", cnt[i], i<k ? ' ' : '\n');
	return 0;
}
