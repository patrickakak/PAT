#include <iostream>
#include <algorithm>
using namespace std;
string add(string a, string b) {
	string sum;
	int carry = 0;
	for (int i = a.length()-1; i >= 0; i--) {
		int tmp = a[i]-'0' + b[i]-'0' + carry;
		sum += '0' + tmp%10;
		carry = tmp / 10;
	}
	if (carry != 0) sum += '1';
	reverse(sum.begin(), sum.end());
	return sum;
}
bool ispalindromic(string s) {
	for (int i = 0, j = s.length()-1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}
int main() {
	string s;
	int k, step = 0;
	cin >> s >> k;
	while (step < k) {
		if (ispalindromic(s)) break;
		string rs = s;
		reverse(rs.begin(), rs.end());
		s = add(s, rs);
		step++;
	}
	printf("%s\n%d", s.c_str(), step);
	return 0;
}
