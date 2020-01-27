#include <iostream>
#include <vector>
using namespace std;
struct node {
	int addr, next, flag;
	char data;
};
vector<node> v(100001);
int main() {
	int fir, sec, n, addr, p;
	cin >> fir >> sec >> n;
	for (int i = 0; i < n; i++) {
		cin >> addr;
		v[addr].addr = addr;
		cin >> v[addr].data >> v[addr].next;
	}
	for (p = fir; p != -1; p = v[p].next)
		v[p].flag = 1;
	for (p = sec; p != -1; p = v[p].next)
		if (v[p].flag == 1) break;
	if (p != -1) printf("%05d", v[p].addr);
	else printf("-1");
	return 0;
}
