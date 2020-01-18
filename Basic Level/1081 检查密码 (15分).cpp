#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
    getchar();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (s.length() < 6) cout << "Your password is tai duan le.\n";
		else {
			bool invalid = false, hasAlpha = false, hasNum = false;
			for (int j = 0; j < s.length(); j++) {
				if (s[j] != '.' && !isalnum(s[j])) invalid = true;
				else if (isalpha(s[j])) hasAlpha = true;
				else if (isdigit(s[j])) hasNum = true;
			}
			if (invalid) cout << "Your password is tai luan le.\n";
			else if (!hasNum) cout << "Your password needs shu zi.\n";
			else if (!hasAlpha) cout << "Your password needs zi mu.\n";
			else cout << "Your password is wan mei.\n";
		}
	}
	return 0;
}
