#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int addr, key, next, flag;
};
vector<node> v(100000);
bool cmp(node a, node b) {
	return a.flag != b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
	int n, fir, addr, cnt=0;
	cin >> n >> fir;
	for (int i=0; i<n; i++) {
		cin >> addr;
		v[addr].addr = addr;
		cin >> v[addr].key >> v[addr].next;
	}
	for (int p = fir; p != -1; p = v[p].next) {
		v[p].flag = 1;
		cnt++;
	}
	if (cnt == 0) printf("0 -1");
	else {
		sort(v.begin(), v.end(), cmp);
		printf("%d %05d\n", cnt, v[0].addr);
		for (int i = 0; i < cnt; i++)
			if (i != cnt - 1) printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
			else printf("%05d %d -1", v[i].addr, v[i].key);
	}
	return 0;
}
