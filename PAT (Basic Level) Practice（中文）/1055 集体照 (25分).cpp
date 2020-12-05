#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	string name;
	int ht;
};
int cmp(struct node a, struct node b) {
	return a.ht != b.ht ? a.ht > b.ht : a.name < b.name;
}
int main() {
	int n, k, m;
	cin >> n >> k;
	vector<node> stu(n);
	for (int i = 0; i < n; i++)
		cin >> stu[i].name >> stu[i].ht;
	sort(stu.begin(), stu.end(), cmp);
	int t = 0, row = k;
	while (row) {
		m = (row == k ? n % k + n / k : n / k);
		vector<string> ans(m);
		ans[m / 2] = stu[t].name;
		int j = m / 2 - 1;
		for (int i = t + 1; i < t + m; i += 2)
			ans[j--] = stu[i].name;
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i += 2)
			ans[j++] = stu[i].name;
		for (int i = 0; i < m; i++) {
			if (i != 0) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
		t += m;
		row--;
	}
	return 0;
}
