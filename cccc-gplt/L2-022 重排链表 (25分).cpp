#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int addr, data, next, flg, order;
};
vector<node> v(100010), w;
int num = 0;
bool cmp(node &a, node &b) {
	return a.flg != b.flg ? a.flg > b.flg : a.order < b.order;
}
int main() {
	int fir, n, addr, data, next;
	cin >> fir >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &addr, &data, &next);
		v[addr] = {addr, data, next};
	}
	for (int p = fir; p != -1; p = v[p].next) {
		v[p].flg = 1;
		v[p].order = num++;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0, j = num-1; i <= j; i++, j--) {
		w.push_back(v[j]);
		if (i < j) w.push_back(v[i]);
	}
	for (int i = 0; i < num; i++)
		if (i == num-1) printf("%05d %d -1", w[i].addr, w[i].data);
		else printf("%05d %d %05d\n", w[i].addr, w[i].data, w[i+1].addr);
	return 0;
}
