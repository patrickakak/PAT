#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) { return a + b < b + a; }
int main() {
	int n;
	cin >> n;
	vector<string> ss(n);
	for (int i = 0; i < n; i++)
		cin >> ss[i];
	sort(ss.begin(), ss.end(), cmp);
	string ans;
	for (int i = 0; i < n; i++)
		ans += ss[i];
	while (ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());
	if (ans.size() == 0) cout << 0;
	else cout << ans;
	return 0;
}
