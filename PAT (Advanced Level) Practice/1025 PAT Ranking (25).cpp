#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string id;
	int loc, g, r;
};
bool cmp(node &a, node &b) {
	return a.g != b.g ? a.g > b.g : a.id < b.id;
}
int main() {
	int n, k, g, sum = 0;
	string id;
	cin >> n;
	vector<node> v;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> id >> g;
			v.push_back(node{id, i+1, g});
		}
		sort(v.begin()+sum, v.begin()+sum+k, cmp);
		v[sum].r = 1;
		for (int j = 1; j < k; j++) {
			v[j+sum].r = j+1;
			if (v[j+sum].g == v[j+sum-1].g) v[j+sum].r = v[j+sum-1].r;
		}
		sum += k;
	}
	printf("%d\n", sum);
	sort(v.begin(), v.end(), cmp);
	int r = 1;
	printf("%s %d %d %d\n", v[0].id.c_str(), r, v[0].loc, v[0].r);
	for (int i = 1; i < sum; i++) {
		if (v[i].g != v[i-1].g) r = i + 1;
		printf("%s %d %d %d\n", v[i].id.c_str(), r, v[i].loc, v[i].r);
	}
	return 0;
}
