#include <iostream>
#include <algorithm>
using namespace std;
void add(string &s, string t) {
	int carry = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		int sum = carry + (s[i] - '0') + (t[i] - '0');
		carry = sum / 10;
		s[i] = sum % 10 + '0';
	}
	if (carry) s = '1' + s;
}
int main() {
	string s;
	int cnt, i;
	cin >> s >> cnt;
	for (i = 0; i <= cnt; i++) {
		string t = s;
		reverse(t.begin(), t.end());
		if (s == t || i == cnt) break;
		add(s, t);
	}
	cout << s << endl << i;
	return 0;
}
