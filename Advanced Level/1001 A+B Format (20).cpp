#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string s = to_string(a + b);
	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
		if (s[i] == '-') continue;
		if ((i + 1) % 3 == s.length() % 3 && i != s.length() - 1) printf(",");
	}
	return 0;
}
