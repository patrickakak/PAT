#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, a[101];
	cin >> n >> m;
	m %= n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (m != 0) {
		reverse(begin(a), begin(a) + n - m);
		reverse(begin(a) + n - m, begin(a) + n);
		reverse(begin(a), begin(a) + n);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n-1) cout << ' ';
	}
	return 0;
}
