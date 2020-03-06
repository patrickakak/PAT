#include <iostream>
#include <vector>
using namespace std;
string a[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string b[] = {"", "Shi", "Bai", "Qian", "Wan", "Yi"};
vector<string> v;
int main() {
	long long n;
	cin >> n;
	string s = to_string(n);
	int l = 0, r = s.length() - 1;
	if (s[0] == '-') {
		v.push_back("Fu");
		l = 1;
	}
	while (r - 4 >= l) r -= 4;
	while (l < s.length()) {
		bool zflag = false;
		for ( ; l <= r; l++)
			if (l > 0 && s[l] == '0') zflag = true;
			else {
				if (zflag == true) {
					v.push_back("ling");
					zflag = false;
				}
				v.push_back(a[s[l]-'0']);
				if (l != r) v.push_back(b[r-l]);
			}
		if (r != s.length()-1) v.push_back(b[(s.length() - r) / 4 + 3]);
		r += 4;
	}
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) printf(" ");
		printf("%s", v[i].c_str());
	}
	return 0;
}
