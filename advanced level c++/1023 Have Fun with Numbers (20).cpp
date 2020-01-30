#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s, ans;
	cin >> s;
	int flag = 0, carry = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		int sum = carry + 2 * (s[i] - '0');
		carry = sum / 10;
		int r = sum % 10;
		ans += ('0' + r);
	}
	if (carry != 0) ans += '1';
	if (is_permutation(s.begin(), s.end(), ans.begin())) flag = 1;
	reverse(ans.begin(), ans.end());
	printf("%s\n%s", flag ? "Yes" : "No", ans.c_str());
	return 0;
}
