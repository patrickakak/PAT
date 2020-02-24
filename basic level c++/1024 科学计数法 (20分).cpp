#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int p = s.find('E');
	string m = s.substr(1, p-1);
	int e = stoi(s.substr(p+1));
	if (s[0] == '-') cout << '-';
	if (e < 0) {
		cout << "0.";
		for (int i = 0; i < abs(e)-1; i++) cout << '0';
		for (int i = 0; i < m.length(); i++)
			if (m[i] != '.') cout << m[i];
	} else {
		printf("%c", m[0]);
		m.erase(0, 2);
		int i;
		for (i = 0; i < e; i++) {
			if (i < m.length()) printf("%c", m[i]);
			else printf("0");
		}
		if (i < m.length()) printf(".");
		for (; i < m.length(); i++) printf("%c", m[i]);
	}
	return 0;
}
