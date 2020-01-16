#include <iostream>
using namespace std;
int main() {
	string s, s1, s2, ans;
	int carry = 0;
	cin >> s >> s1 >> s2;
	ans = s;
	string ss1(s.length() - s1.length(), '0');
	s1 = ss1 + s1;
	string ss2(s.length() - s2.length(), '0');
	s2 = ss2 + s2;
	for (int i = s.length() - 1; i >= 0; i--) {
		int mod = s[i] == '0' ? 10 : (s[i] - '0');
		ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
	}
	if (carry != 0) ans = '1' + ans;
	while (ans.length() > 0 && ans[0] == '0') ans.erase(ans.begin());
	if (ans.size() == 0) cout << 0;
	else cout << ans;
	return 0;
}
