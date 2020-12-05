#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool ispalindromic(string &s) {
	for (int i=0, j=s.length()-1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}
int main() {
	int n, d, y;
	string m;
	cin >> n;
	string ss[] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	unordered_map<string, int> mp;
	for (int i = 1; i <= 12; i++)
		mp[ss[i]] = i;
	for (int i = 0; i < n; i++) {
		cin >> m;
		scanf("%d, %d", &d, &y);
		string stry = to_string(y);
		stry.insert(0, 4-stry.length(), '0');
		string strm = to_string(mp[m]);
		strm.insert(0, 2-strm.length(), '0');
		string strd = to_string(d);
		strd.insert(0, 2-strd.length(), '0');
		string s = stry + strm + strd;
		printf("%c %s\n", ispalindromic(s) ? 'Y' : 'N', s.c_str());
	}
	return 0;
}
