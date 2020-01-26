#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	s.insert(0, 4 - s.length(), '0');
	do {
		string a = s, b = s;
		sort(a.rbegin(), a.rend());
		sort(b.begin(), b.end());
		s = to_string(stoi(a) - stoi(b));
		s.insert(0, 4 - s.length(), '0');
		cout << a << " - " << b << " = " << s << endl;
	} while (s != "6174" && s != "0000");
	return 0;
}
