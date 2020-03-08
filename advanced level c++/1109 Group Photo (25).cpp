#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string nm;
	int ht;
};
int cmp(node &a, node &b) {
	return a.ht != b.ht ? a.ht > b.ht : a.nm < b.nm;
}
int main() {
	int n, k, m;
	cin >> n >> k;
	vector<node> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].nm >> v[i].ht;
	sort(v.begin(), v.end(), cmp);
	int t = 0, row = k;
	while (row) {
		m = (row == k ? n % k + n / k : n / k);
		vector<string> ans(m);
		ans[m / 2] = v[t].nm;
		int j = m / 2 - 1;
		for (int i = t + 1; i < t + m; i += 2)
			ans[j--] = v[i].nm;
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i += 2)
			ans[j++] = v[i].nm;
		for (int i = 0; i < m; i++) {
			if (i != 0) printf(" ");
			printf("%s", ans[i].c_str());
		}
		printf("\n");
		t += m;
		row--;
	}
	return 0;
}
