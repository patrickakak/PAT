#include <iostream>
using namespace std;
char num[10] = {'a','b','c','d','e','f','g','h','i','j'};
char unit[3] = {'S','B','Q'};
char wei[2] = {'W','Y'};
int main() {
	string s;
	cin >> s;
	int len = s.length();
	int l = 0, r = len-1;
	while (r - 4 >= 0) r -= 4;
	bool flag = false;
	int zcnt = 0;
	while (l < len) {
		while (l <= r) {
			int tmp = s[l]-'0';
			if (tmp != 0 && flag == true) {
				cout << num[0];
				flag = false;
			}
			if (l > 0 && tmp == 0) {
				zcnt++;
				flag = true;
			} else cout << num[tmp];
			if (l != r && tmp != 0) cout << unit[r-l-1];
			l++;
		}
		if (r != len - 1) {
			if (zcnt==4 && r==len-5) ;
			else cout << wei[(len-r)/4-1];
		}
		r += 4;
	}
	return 0;
}
