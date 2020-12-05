#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	char c;
	string s;
	scanf("%d %c\n", &n, &c);
	getline(cin, s);
	reverse(s.begin(), s.end());
	if (s.length() < n) for (int i=0, d=n-s.length(); i < d; i++) s += c;
	else s = s.substr(0, n);
	reverse(s.begin(), s.end());
	printf("%s\n", s.c_str());
	return 0;
}
