#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr, key, next, flag;
};
vector<node> v(100010);
bool cmp(node &a, node &b) {
	return a.flag != b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
	int n, fir, addr, key, next, cnt = 0;
	cin >> n >> fir;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		v[addr] = node{addr, key, next};
	}
	for (int p = fir; p != -1; p = v[p].next) {
		v[p].flag++;
		cnt++;
	}
	sort(v.begin(), v.end(), cmp);
	if (cnt == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", cnt, v[0].addr);
	for (int i = 0; i < cnt; i++)
		if (i != cnt-1) printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
		else printf("%05d %d -1", v[i].addr, v[i].key);
	return 0;
}
