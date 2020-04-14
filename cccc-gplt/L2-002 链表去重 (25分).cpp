#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
	int addr, key, next;
};
unordered_map<int, bool> m;
vector<node> v(100010), a, b;
int main() {
	int fir, n, addr, key, next;
	cin >> fir >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		v[addr] = node{addr, key, next};
	}
	for (int p = fir; p != -1; p = v[p].next)
		if (m[abs(v[p].key)] == false) {
			m[abs(v[p].key)] = true;
			a.push_back(v[p]);
		} else b.push_back(v[p]);
	for (int i = 0; i < a.size(); i++)
		if (i != a.size()-1) printf("%05d %d %05d\n", a[i].addr, a[i].key, a[i+1].addr);
		else printf("%05d %d -1\n", a[i].addr, a[i].key);
	for (int i = 0; i < b.size(); i++)
		if (i != b.size()-1) printf("%05d %d %05d\n", b[i].addr, b[i].key, b[i+1].addr);
		else printf("%05d %d -1", b[i].addr, b[i].key);
	return 0;
}
