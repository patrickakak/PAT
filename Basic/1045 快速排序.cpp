#include <iostream>
#include <algorithm>
#include <vector>
int v[100000];
using namespace std;
int main() {
	int n, max = 0, cnt = 0;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] > max) v[cnt++] = b[i];
		if (b[i] > max) max = b[i];
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		if (i != 0) cout << ' ';
		cout << v[i];
	}
	cout << endl;
	return 0;
}
