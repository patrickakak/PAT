#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int nc, np, ans = 0;
	cin >> nc;
	vector<int> c(nc);
	for (int i = 0; i < nc; i++) scanf("%d", &c[i]);
	cin >> np;
	vector<int> p(np);
	for (int i = 0; i < np; i++) scanf("%d", &p[i]);
	sort(c.begin(), c.end());
	sort(p.begin(), p.end());
	for (int i = 0, j = 0; i < nc && j < np && c[i] < 0 && p[j] < 0; i++, j++)
		ans += c[i] * p[j];
	for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0 && c[i] > 0 && p[j] > 0; i--, j--)
		ans += c[i] * p[j];
	printf("%d", ans);
	return 0;
}
