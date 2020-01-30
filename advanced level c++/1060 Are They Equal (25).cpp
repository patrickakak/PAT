#include <iostream>
using namespace std;
string f(string s, int &e, int n) {
	int k = 0;
	while (s.length() > 0 && s[0] == '0') s.erase(s.begin());
	if (s[0] == '.') {
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--;
		}
	} else {
		while (k < (int)s.length() && s[k] != '.') {
			k++;
			e++;
		}
		if (k < (int)s.length()) s.erase(s.begin() + k);
	}
	if (s.length() == 0) e = 0;
	string res;
	for (int i=0, k=0; i < n; i++, k++)
		if (k < (int)s.length()) res += s[k];
		else res += '0';
	return res;
}
int main() {
	int n, e1 = 0, e2 = 0;
	string a, b;
	cin >> n >> a >> b;
	string s1 = f(a, e1, n);
	string s2 = f(b, e2, n);
	if (s1 == s2 && e1 == e2) cout << "YES 0." << s1 << "*10^" << e1;
	else cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2;
	return 0;
}
