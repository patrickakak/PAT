#include <iostream>
using namespace std;
char a[] = {'a','b','c','d','e','f','g','h','i','j'};
char b[] = {'S','B','Q'};
char c[] = {'W','Y'};
int main() {
	string s;
	cin >> s;
	int len = s.length(), l = 0, r = len - 1, zcnt = 0;
	while (r - 4 >= 0) r -= 4;
	bool flag = false;
	while (l < len) {
		while (l <= r) {
			int tmp = s[l] - '0';
			if (tmp != 0 && flag == true) {
				cout << a[0];
				flag = false;
			}
			if (l > 0 && tmp == 0) {
				zcnt++;
				flag = true;
			} else cout << a[tmp];
			if (l != r && tmp != 0) cout << b[r-l-1];
			l++;
		}
		if (r != len - 1) {
			if (zcnt == 4 && r == len - 5) ;
			else cout << c[(len-r)/4 - 1];
		}
		r += 4;
	}
	return 0;
}
