#include <iostream>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	s += '#';
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '6') {
			if (cnt != 0) {
				if (cnt > 9) printf("27");
				else if (cnt > 3) printf("9");
				else for (int j = 0; j < cnt; j++) printf("6");
			}
			if (i != s.length()-1) printf("%c", s[i]);
			cnt = 0;
		}
		if (s[i] == '6') {
			if (cnt == 0) cnt++;
			if (cnt != 0 && i-1 >= 0 && s[i-1] == '6') cnt++;
		}
	}
	return 0;
}
