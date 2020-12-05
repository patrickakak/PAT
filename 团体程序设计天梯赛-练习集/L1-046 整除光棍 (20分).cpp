#include <iostream>
using namespace std;
string div(string &s, int n, int &r) {
	string q;
	r = 0;
	for (int i = 0; i < s.length(); i++) {
		r = 10*r + (s[i]-'0');
		if (r < n) q += '0';
		else {
			q += r/n + '0';
			r %= n;
		}
	}
	while (q.length() > 0 && q[0] == '0') q.erase(q.begin());
	return q;
}
int main() {
	int n, r;
	cin >> n;
	string s, q;
	while (1) {
		s += "1";
		q = div(s, n, r);
		if (r == 0) break;
	}
	printf("%s %d\n", q.c_str(), s.length());
	return 0;
}
