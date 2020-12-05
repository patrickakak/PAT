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
		while (k < s.length() && s[k] != '.') {
			k++;
			e++;
		}
		if (k < s.length()) s.erase(s.begin() + k);
	}
	if (s.length() == 0) e = 0;
	string res;
	for (int i = 0, k = 0; i < n; i++, k++)
		if (k < s.length()) res += s[k];
		else res += '0';
	return res;
}
int main() {
	int n, e1 = 0, e2 = 0;
	string a, b;
	cin >> n >> a >> b;
	string m1 = f(a, e1, n);
	string m2 = f(b, e2, n);
	if (m1 == m2 && e1 == e2) printf("YES 0.%s*10^%d", m1.c_str(), e1);
	else printf("NO 0.%s*10^%d 0.%s*10^%d", m1.c_str(), e1, m2.c_str(), e2);
	return 0;
}
