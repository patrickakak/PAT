#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int l, n;
	cin >> l >> n;
	int pos = pow(26, l) - n;
	string s;
	for (int i = 0; i < l; i++) {
		s += pos%26 + 'a';
		pos /= 26;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
