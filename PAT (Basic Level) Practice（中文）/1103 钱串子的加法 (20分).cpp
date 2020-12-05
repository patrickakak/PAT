#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	string a, b, s;
	cin >> a >> b;
	string str = "0123456789abcdefghijklmnopqrst";
	unordered_map<char, int> m;
	for (int i = 0; i < 30; i++)
		m[str[i]] = i;
	int len = max(a.length(), b.length());
	a.insert(0, len-a.length(), '0');
	b.insert(0, len-b.length(), '0');
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int sum = m[a[i]] + m[b[i]] + carry;
		if (sum >= 30) {
			sum -= 30;
			carry = 1;
		} else carry = 0;
		s += str[sum];
	}
	if (carry == 1) s += '1';
	while (s.length()>1 && s[0]=='0') s.erase(0, 1);
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
