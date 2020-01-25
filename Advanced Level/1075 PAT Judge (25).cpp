#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int uid, perfect, r, tot, print;
	vector<int> p;
};
bool cmp(node a, node b) {
	if (a.tot != b.tot) return a.tot > b.tot;
	else if (a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.uid < b.uid;
}
int main() {
	int n, k, m, uid, pid, g;
	cin >> n >> k >> m;
	vector<int> p(k, -1);
	vector<node> v(n);
	for (int i = 0; i < n; i++) v[i].p = p;
	for (int i = 0; i < k; i++) cin >> p[i];
	for (int i = 0; i < m; i++) {
		cin >> uid >> pid >> g;
		v[uid-1].uid = uid;
		int t = max(g, v[uid-1].p[pid-1]);
		if (t != -1) {
			v[uid-1].print = 1;
			v[uid-1].p[pid-1] = t;
		} else v[uid-1].p[pid-1] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			if (v[i].p[j] != -1) v[i].tot += v[i].p[j];
			if (v[i].p[j] == p[j]) v[i].perfect++;
		}
	sort(v.begin(), v.end(), cmp);
	v[0].r = 1;
	for (int i = 1; i < n; i++) {
		v[i].r = i + 1;
		if (v[i].tot == v[i-1].tot) v[i].r = v[i-1].r;
	}
	for (int i = 0; i < n; i++) {
		if (!v[i].print) continue;
		printf("%d %05d %d", v[i].r, v[i].uid, v[i].tot);
		for (int j = 0; j < k; j++)
			if (v[i].p[j] != -1) printf(" %d", v[i].p[j]);
			else printf(" -");
		printf("\n");
	}
	return 0;
}
