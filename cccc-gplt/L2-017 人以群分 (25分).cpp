#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, half = 0, sum = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (i < n/2) half += v[i];
		sum += v[i];
	}
	printf("Outgoing #: %d\n", n/2+n%2);
	printf("Introverted #: %d\n", n/2);
	printf("Diff = %d\n", sum-2*half);
	return 0;
}
