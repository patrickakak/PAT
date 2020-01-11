#include <iostream>
#include <map>
using namespace std;
int main() {
	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;
	for (auto it = m.begin(); it != m.end(); it++)
		cout << it->first << ':' << it->second << endl;
	return 0;
}
