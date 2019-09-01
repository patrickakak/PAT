/**
 * Sample input:
 * 5 32 321 3214 0229 87
 * ----------------------
 * Sample output:
 * 22932132143287
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
string str[maxn];

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	sort(str, str + n, cmp);

	string ans;
	for (int i = 0; i < n; i++)
		ans += str[i];
	while (ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());

	if (ans.size() == 0) cout << 0;
	else cout << ans;

	return 0;
}


