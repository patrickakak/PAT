#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int id, amt, n;
};
vector<node> v(10010);
bool cmp(node &a, node &b) {
	if (a.amt != b.amt) return a.amt > b.amt;
	else if (a.n != b.n) return a.n > b.n;
	else return a.id < b.id;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, sum = 0, id, p;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d%d", &id, &p);
			sum += p;
			v[id].amt += p;
			v[id].n++;
		}
		v[i].id = i;
		v[i].amt -= sum;
	}
	sort(v.begin()+1, v.begin()+n+1, cmp);
	for (int i = 1; i <= n; i++)
		printf("%d %.2f\n", v[i].id, v[i].amt/100.0);
	return 0;
}
