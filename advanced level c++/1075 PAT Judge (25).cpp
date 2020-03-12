#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int uid, perf, r, tot, print;
	vector<int> p;
};
bool cmp(node &a, node &b) {
	if (a.tot != b.tot) return a.tot > b.tot;
	else if (a.perf != b.perf) return a.perf > b.perf;
	else return a.uid < b.uid;
}
int main() {
	int n, k, m, uid, pid, g;
	scanf("%d%d%d", &n, &k, &m);
	vector<int> p(k+1, -1);
	vector<node> v(n+1);
	for (int i = 1; i <= n; i++) v[i].p = p;
	for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
	while (m--) {
		scanf("%d%d%d", &uid, &pid, &g);
		v[uid].uid = uid;
		int t = max(g, v[uid].p[pid]);
		if (t == -1) v[uid].p[pid] = 0;
		else {
			v[uid].print = 1;
			v[uid].p[pid] = t;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			if (v[i].p[j] != -1) v[i].tot += v[i].p[j];
			if (v[i].p[j] == p[j]) v[i].perf++;
		}
	sort(v.begin()+1, v.end(), cmp);
	v[1].r = 1;
	for (int i = 2; i <= n; i++) {
		v[i].r = i;
		if (v[i].tot == v[i-1].tot) v[i].r = v[i-1].r;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i].print) continue;
		printf("%d %05d %d", v[i].r, v[i].uid, v[i].tot);
		for (int j = 1; j <= k; j++)
			if (v[i].p[j] != -1) printf(" %d", v[i].p[j]);
			else printf(" -");
		printf("\n");
	}
	return 0;
}
