#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
struct p {
	int date, t, is, ser=0;
} f[10010];
bool cmp1(p &a, p &b) {
	return a.date < b.date;
}
bool cmp2(p &a, p &b) {
	return a.ser < b.ser;
}
int sta[110], c[110], vis[110];
queue<int> q[2];
int main() {
	int n, k, m, hh, mm, ss, tid, pos = 1, a[2] = {0};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &f[i].t, &f[i].is);
		f[i].date = hh*60*60 + mm*60 + ss;
		f[i].t = min(f[i].t*60, 2*60*60);
	}
	sort(f+1, f+n+1, cmp1);
	cin >> k >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tid);
		sta[tid] = 1;
	}
	for (int i = 8*60*60; i < 21*60*60; i++) {
		if (pos<=n && f[pos].date==i) q[f[pos].is].push(pos), pos++;
		if (!q[0].empty()) a[0] = q[0].front();
		if (!q[1].empty()) a[1] = q[1].front();
		queue<int> v;
		for (int j = 1; j <= k; j++) {
			if (vis[j] && f[vis[j]].ser+f[vis[j]].t==i) vis[j] = 0;
			if (!vis[j] && sta[j]) v.push(j);
		}
		while (!q[1].empty() && !v.empty()) {
			q[1].pop();
			int num = v.front();
			v.pop();
			vis[num] = a[1];
			c[num]++;
			f[a[1]].ser = i;
			a[1] = !q[1].empty() ? q[1].front() : 0;
		}
		for (int j = 1; j <= k; j++)
			if (!vis[j]) {
				if (!a[0] && !a[1]) continue;
				int op = 0;
				if (a[1] && (!a[0] || f[a[1]].date<f[a[0]].date)) op = 1;
				q[op].pop();
				vis[j] = a[op];
				f[a[op]].ser = i;
				a[op] = !q[op].empty() ? q[op].front() : 0;
				c[j]++;
			}
	}
	sort(f+1, f+n+1, cmp2);
	for (int i = 1; i <= n; i++)
		if (f[i].ser != 0)
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", f[i].date/3600, f[i].date%3600/60, 
					f[i].date%60, f[i].ser/3600, f[i].ser%3600/60, f[i].ser%60, (int)round((f[i].ser-f[i].date)/60.0));
	for (int i = 1; i <= k; i++)
		printf("%d%c", c[i], i<k ? ' ' : '\n');
	return 0;
}
