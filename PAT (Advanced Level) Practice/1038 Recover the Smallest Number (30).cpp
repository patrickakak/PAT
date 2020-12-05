#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string &a, string &b) {
	return a + b < b + a;
}
int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string s;
	for (int i = 0; i < n; i++) s += v[i];
	while (s.length() != 0 && s[0] == '0') s.erase(s.begin());
	if (s.length() == 0) printf("0");
	else printf("%s", s.c_str());
	return 0;
}
