#include <iostream>
using namespace std;
string a[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string b[] = {"", "Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
	int n;
	cin >> n;
	string s = to_string(n);
	int l = 0, r = s.length() - 1;
	if (s[0] == '-') {
		printf("Fu");
		l = 1;
	}
	while (r - 4 >= l) r -= 4;
	while (l < s.length()) {
		bool zflag = false, isPrint = false;
		while (l <= r) {
			if (l > 0 && s[l] == '0') zflag = true;
			else {
				if (zflag == true) {
					printf(" ling");
					zflag = false;
				}
				if (l > 0) printf(" ");
				cout << a[s[l]-'0'];
				isPrint = true;
				if (l != r) cout << ' ' << b[r-l];
			}
			l++;
		}
		if (isPrint == true && r != s.length()-1)
			cout << ' ' << b[(s.length() - r) / 4 + 3];
		r += 4;
	}
	return 0;
}
