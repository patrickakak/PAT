#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string name, id;
	int g;
};
bool cmp(node &a, node &b) {
	return a.g > b.g;
}
int main() {
	int n, g1, g2, cnt = 0;
	cin >> n;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].id >> v[i].g;
	sort(v.begin(), v.end(), cmp);
	cin >> g1 >> g2;
	for (int i = 0; i < n; i++)
		if (v[i].g >= g1 && v[i].g <= g2) {
			cnt++;
			cout << v[i].name << ' ' << v[i].id << endl;
		}
	if (cnt == 0) cout << "NONE";
	return 0;
}
