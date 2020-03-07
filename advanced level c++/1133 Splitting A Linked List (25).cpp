#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr, key, next, flag, id;
};
vector<node> v(100010);
bool cmp(node &a, node &b) {
	return a.flag != b.flag ? a.flag > b.flag : a.id < b.id;
}
int main() {
	int fir, n, k, addr, key, next, cnt = 0;
	cin >> fir >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		v[addr] = node{addr, key, next};
	}
	for (int p = fir; p != -1; p = v[p].next) {
		if (v[p].key < 0) v[p].flag = 3;
		else if (v[p].key >= 0 && v[p].key <= k) v[p].flag = 2;
		else v[p].flag = 1;
		v[p].id = cnt++;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < cnt; i++)
		if (i != cnt-1) printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
		else printf("%05d %d -1", v[i].addr, v[i].key);
	return 0;
}
