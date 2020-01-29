#include <iostream>
#include <map>
using namespace std;
int main() {
	string s, w;
	getline(cin, s);
	map<string, int> m;
	for (int i = 0; i < s.length(); i++) {
		if (isalnum(s[i])) w += tolower(s[i]);
		if (!isalnum(s[i]) || i == s.length() - 1){
			if (w.length() != 0) m[w]++;
			w = "";
		}
	}
	int maxn = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > maxn) {
			w = it->first;
			maxn = it->second;
		}
	cout << w << " " << maxn;
	return 0;
}
