#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	int n;
	getline(cin, s);
	cin >> n;
	int len = s.length();
	if (n > len) n = n % len;
	reverse(s.begin(), s.begin()+n);
	reverse(s.begin()+n, s.end());
	reverse(s.begin(), s.end());
	cout << s;
	return 0;
}
