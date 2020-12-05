#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	long n, p, len = 0;
	cin >> n >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		for (int j = i + len; j < n; j++)
			if (v[j] <= v[i] * p) len++;
			else break;
	printf("%d", len);
	return 0;
}
