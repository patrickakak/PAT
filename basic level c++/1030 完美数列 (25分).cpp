#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, p, d = 0;
	cin >> n >> p;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		if (v[i] > v[0]*p) break;
		else d++;
	for (int i = 1; i < v.size(); ) {
		if (i+d >= v.size()) break;
		if (v[i+d] <= v[i]*p) d++;
		else i++;
	}
	printf("%d\n", d);
	return 0;
}
