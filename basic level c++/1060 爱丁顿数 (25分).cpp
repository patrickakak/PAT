#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, e = 1;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend()-1);
	while (e<v[e] && e<=n) e++;
	printf("%d\n", e-1);
	return 0;
}
