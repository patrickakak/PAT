#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node {
	int id, setcnt, area, flag, mbrcnt;
};
vector<node> v(10000);
vector<int> father(10000);
int find(int x) {
	int a = x;
	while (x != father[x]) x = father[x];
	while (a != father[a]) {
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}
void Union(int a, int b) {
	int faA = find(a);
	int faB = find(b);
	if (faA < faB) father[faB] = faA;
	else if (faB < faA) father[faA] = faB;
}
bool cmp(node &a, node &b) {
	double avera = 1.0 * a.area / a.mbrcnt, averb = 1.0 * b.area / b.mbrcnt;
	return avera != averb ? avera > averb : a.id < b.id;
}
int main() {
	int n, id, f, m, k, cid, setcnt, area;
	cin >> n;
	for (int i = 0; i < 10000; i++) father[i] = i;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &id, &f, &m, &k);
		if (f != -1) {
			v[f].flag = 1;
			Union(id, f);
		}
		if (m != -1) {
			v[m].flag = 1;
			Union(id, m);
		}
		for (int j = 0; j < k; j++) {
			scanf("%d", &cid);
			v[cid].flag = 1;
			Union(id, cid);
		}
		scanf("%d%d", &setcnt, &area);
		v[id] = {id, setcnt, area, 1};
	}
	map<int, node> mp;
	for (int i = 0; i < 10000; i++) {
		if (v[i].flag == 0) continue;
		int rt = find(i);
		mp[rt].id = rt;
		mp[rt].setcnt += v[i].setcnt;
		mp[rt].area += v[i].area;
		mp[rt].mbrcnt++;
	}
	printf("%d\n", mp.size());
	vector<node> ns;
	for (auto it : mp) ns.push_back(it.second);
	sort(ns.begin(), ns.end(), cmp);
	for (int i = 0; i < ns.size(); i++) {
		node tmp = ns[i];
		int cnt = tmp.mbrcnt;
		printf("%04d %d %.3f %.3f\n", tmp.id, cnt, 1.0*tmp.setcnt/cnt, 1.0*tmp.area/cnt);
	}
	return 0;
}
