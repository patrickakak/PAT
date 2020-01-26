
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	// freopen("tst.txt", "r", stdin);
	string s, word = "";
	map<string, int> m;

	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (isalnum(s[i])) {
			s[i] = tolower(s[i]);
			word += s[i];
		}
		if (!isalnum(s[i]) || i==s.length()-1)
			if (word != "") {
				if (m.find(word) != m.end()) m[word]++;
				else m[word] = 1;
				word = "";
			}
	}
	int Max = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > Max) {
			Max = it->second;
			word = it->first;
		}
	printf("%s %d", word.c_str(), Max);
	return 0;
}

