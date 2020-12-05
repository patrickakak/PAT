#include <iostream>
using namespace std;
int main() {
	int n, t, a[10001] = {0};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		a[abs(t-i)]++;
	}
	for (int i = 10000; i >= 0; i--)
		if (a[i] >= 2) cout << i << ' ' << a[i] << endl;
	return 0;
}
