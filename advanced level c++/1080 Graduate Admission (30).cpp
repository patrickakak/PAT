#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int id, ge, gi, fin;
	vector<int> choice;
};
bool cmp1(node &a, node &b) {
	return a.fin != b.fin ? a.fin > b.fin : a.ge > b.ge;
}
bool cmp2(node &a, node &b) {
	return a.id < b.id;
}
int main() {
	int n, m, k, quota[110];
	scanf("%d%d%d", &n, &m, &k);
	vector<node> v(n), sch[110];
	for (int i = 0; i < m; i++) scanf("%d", &quota[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &v[i].ge, &v[i].gi);
		v[i].id = i;
		v[i].fin = v[i].ge + v[i].gi;
		v[i].choice.resize(k);
		for (int j = 0; j < k; j++) scanf("%d", &v[i].choice[j]);
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			int sid = v[i].choice[j], sz = sch[sid].size();
			if (sz < quota[sid] || v[i].fin == sch[sid][sz-1].fin && v[i].ge == sch[sid][sz-1].ge) {
				sch[sid].push_back(v[i]);
				break;
			}
		}
	for (int i = 0; i < m; i++) {
		sort(sch[i].begin(), sch[i].end(), cmp2);
		for (int j = 0; j < sch[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", sch[i][j].id);
		}
		printf("\n");
	}
	return 0;
}
