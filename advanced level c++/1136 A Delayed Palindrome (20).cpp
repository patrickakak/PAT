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
	cin >> s;
	int step = 0;
	while (step < 10) {
		if (ispalindromic(s)) break;
		string rs = s;
		reverse(rs.begin(), rs.end());
		string sum = add(s, rs);
		printf("%s + %s = %s\n", s.c_str(), rs.c_str(), sum.c_str());
		s = sum;
		step++;
	}
	if (step == 10) printf("Not found in 10 iterations.");
	else printf("%s is a palindromic number.", s.c_str());
	return 0;
}
