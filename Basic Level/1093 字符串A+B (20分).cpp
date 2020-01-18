#include <iostream>
using namespace std;
int main() {
	string s1, s2, s;
	int hash[128] = {0};
	getline(cin, s1);
	getline(cin, s2);
	s = s1 + s2;
	for (int i = 0; i < s.length(); i++) {
		if (hash[s[i]] == 0) cout << s[i];
		hash[s[i]] = 1;
	}
	return 0;
}
