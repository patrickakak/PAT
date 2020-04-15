#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int l, n;
	cin >> l >> n;
	int maxn = pow(26, l);
	int x = maxn - n;
	string s;
	for (int i = 0; i < l; i++) {
		s += x%26 + 'a';
		x /= 26;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
