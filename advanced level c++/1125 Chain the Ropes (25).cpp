#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	int ans = v[0];
	for (int i = 1; i < n; i++) ans = (ans + v[i]) / 2;
	printf("%d", ans);
	return 0;
}
