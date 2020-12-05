#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string s;
	int r, g;
};
bool cmp(node &a, node &b) {
	return a.g != b.g ? a.g > b.g : a.s < b.s;
}
int main() {
	int n, g, k, sum = 0;
	cin >> n >> g >> k;
	vector<node> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].s >> v[i].g;
		if (v[i].g >= g) sum += 50;
		else if (v[i].g >= 60) sum += 20;
	}
	sort(v.begin(), v.end(), cmp);
	v[0].r = 1;
	for (int i = 1; i < v.size(); i++) {
		v[i].r = i + 1;
		if (v[i].g == v[i-1].g) v[i].r = v[i-1].r;
	}
	printf("%d\n", sum);
	for (int i = 0; i < v.size(); i++)
		if (v[i].r <= k) printf("%d %s %d\n", v[i].r, v[i].s.c_str(), v[i].g);
		else break;
	return 0;
}
