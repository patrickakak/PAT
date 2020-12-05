#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, max = 0;
	cin >> n;
	vector<int> a(n), b(n), v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] > max) v.push_back(b[i]);
		if (b[i] > max) max = b[i];
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) printf(" ");
		printf("%d", v[i]);
	}
	cout << endl;
	return 0;
}
