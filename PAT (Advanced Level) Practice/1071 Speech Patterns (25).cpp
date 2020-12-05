#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	string s, w, maxs;
	getline(cin, s);
	s += '#';
	unordered_map<string, int> m;
	for (int i = 0; i < s.length(); i++)
		if (isalpha(s[i]) || isdigit(s[i])) w += tolower(s[i]);
		else {
			if (w != "") m[w]++;
			w = "";
		}
	int maxn = 0;
	for (auto it : m)
		if (maxn < it.second) {
			maxs = it.first;
			maxn = it.second;
		} else if (maxn == it.second && maxs > it.first)
			maxs = it.first;
	printf("%s %d", maxs.c_str(), maxn);
	return 0;
}
