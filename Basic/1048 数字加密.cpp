#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b;
	int lena = a.length(), lenb = b.length();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (lena > lenb) b.append(lena - lenb, '0');
	else a.append(lenb - lena, '0');
	char str[14] = {"0123456789JQK"};
	for (int i = 0; i < a.length(); i++)
		if (i % 2 == 0)
			c += str[(a[i] - '0' + b[i] - '0') % 13];
		else {
			int tmp = b[i] - a[i];
			if (tmp < 0) tmp = tmp + 10;
			c += str[tmp];
		}
	for (int i = c.length() - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}
