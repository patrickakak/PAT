#include <iostream>
#include <vector>
using namespace std;
struct node {
	int addr, next, flag;
	char data;
};
vector<node> v(100010);
int main() {
	int fir1, fir2, n, addr, next;
	char data;
	cin >> fir1 >> fir2 >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &addr, &data, &next);
		v[addr] = node{addr, next, 0, data};
	}
	for (int p = fir1; p != -1; p = v[p].next) v[p].flag++;
	for (int p = fir2; p != -1; p = v[p].next)
		if (v[p].flag == 1) {
			printf("%05d", v[p].addr);
			return 0;
		}
	printf("-1");
	return 0;
}
