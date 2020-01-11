#include <iostream>
#include <string>
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
		cout << m[0];
		int j = 2, cnt = 0;
		for (; j < m.length() && cnt < e; j++, cnt++) cout << m[j];
		if (j == m.length())
			for (int k = 0; k < e-cnt; k++) cout << '0';
		else {
			cout << '.';
			for (int k = j; k < m.length(); k++) cout << m[k];
		}
	}
	return 0;
}
