#include <iostream>
using namespace std;
int main() {
	char c;
	cin >> c;
	getchar();
	string s, num;
	getline(cin, s);
	int cnt = 1;
	if (c == 'C') {
		char pre = s[0];
		for (int i = 1; i < s.length(); i++)
			if (s[i] == pre) cnt++;
			else {
				if (cnt > 1) cout << cnt;
				cout << pre;
				cnt = 1;
				pre = s[i];
			}
		if (cnt > 1) cout << cnt;
		cout << pre;
	} else
		for (int i = 0; i < s.length(); i++)
			if (isdigit(s[i])) num += s[i];
			else {
				if (num.length() > 0) cnt = stoi(num);
				while (cnt--) cout << s[i];
				cnt = 1;
				num = "";
			}
	return 0;
}
