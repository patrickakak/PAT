#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct stu {
	int id, d, c, r;
};
vector<stu> v;
bool cmp(stu &a, stu &b) {
	if (a.r != b.r) return a.r < b.r;
	else if (a.d+a.c != b.d+b.c) return a.d+a.c > b.d+b.c;
	else if (a.d != b.d) return a.d > b.d;
	else return a.id < b.id;
}
int main() {
	int n, l, h, id, d, c;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &id, &d, &c);
		if (d>=l && c>=l) {
			if (d>=h && c>=h) v.push_back({id, d, c, 1});
			else if (d >= h) v.push_back({id, d, c, 2});
			else if (d<h && c<h && d>=c) v.push_back({id, d, c, 3});
			else v.push_back({id, d, c, 4});
		}
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", (int)v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%08d %d %d\n", v[i].id, v[i].d, v[i].c);
	return 0;
}
