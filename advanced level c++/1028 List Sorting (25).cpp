#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int id, g;
	string nm;
};
int n, c;
bool cmp(node &a, node &b) {
	if (c == 1) return a.id < b.id;
	else if (c == 2) return a.nm != b.nm ? a.nm < b.nm : a.id < b.id;
	else return a.g != b.g ? a.g < b.g : a.id < b.id;
}
int main() {
	cin >> n >> c;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].id >> v[i].nm >> v[i].g;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		printf("%06d %s %d\n", v[i].id, v[i].nm.c_str(), v[i].g);
	return 0;
}
