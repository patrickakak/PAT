#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, e = 0;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend()-1);
	for (int i = 1; i <= n; i++)
		if (v[i] > i) e++;
		else break;
	printf("%d", e);
	return 0;
}
