#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b;
	int len = max(a.length(), b.length());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	b.append(len - b.length(), '0');
	a.append(len - a.length(), '0');
	string ss = "0123456789JQK";
	for (int i = 0; i < a.length(); i++)
		if (i % 2 == 0) c += ss[(a[i] - '0' + b[i] - '0') % 13];
		else {
			int tmp = b[i] - a[i];
			c += ss[tmp < 0 ? tmp+=10 : tmp];
		}
	for (int i = c.length() - 1; i >= 0; i--) printf("%c", c[i]);
	return 0;
}
