#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string nm;
	int ht;
};
bool cmp(node &a, node &b) {
	return a.ht != b.ht ? a.ht > b.ht : a.nm < b.nm;
}
int main() {
	int n, k, m, cnt = 0;
	cin >> n >> k;
	vector<node> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].nm >> v[i].ht;
	sort(v.begin(), v.end(), cmp);
	for (int row = k; row > 0; row--) {
		m = row == k ? n/k + n%k : n/k;
		vector<node> t(m);
		t[m/2] = v[cnt++];
		for (int j = 1; j < m; j++) {
			int left = m/2 - j;
			if (left >= 0) t[left] = v[cnt++];
			int right = m/2 + j;
			if (right < m) t[right] = v[cnt++];
		}
		for (int j = 0; j < m; j++) {
			if (j != 0) printf(" ");
			printf("%s", t[j].nm.c_str());
		}
		printf("\n");
	}
	return 0;
}
