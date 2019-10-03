/**
 * Sample input:
 * Can1: "Can a can can a can?  It can!"
 * -------------------------------------
 * Sample output:
 * can 5
 */
#include <cstdio>
#include <map>  // red-black tree
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// freopen("tst.txt", "r", stdin);
	map<string, int> count;
	string str;
	int i = 0;

	getline(cin, str);
	while (i < (int)str.length()) {
		string word;
		while (i < (int)str.length() && isalnum(str[i])) {
			str[i] = tolower(str[i]);
			word += str[i];
			i++;
		}
		if (word != "") { 	// in case string like: "a"
			if (count.find(word) == count.end()) count[word] = 1;
			else count[word]++;
		}
		while (i < (int)str.length() && !isalnum(str[i]))
			i++;
	}
	string ans;
	int MAX = 0;
	for (map<string, int>::iterator it=count.begin(); it != count.end(); it++)
		if (it->second > MAX) {
			MAX = it->second;
			ans = it->first;
		}
	cout << ans << " " << MAX << endl;

	return 0;
}

