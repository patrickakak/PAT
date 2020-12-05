#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	string s;
	cin >> s;
	unordered_map<char, int> m;
	for (int i = 0; i < s.length(); i++) {
		if (toupper(s[i]) == 'G') m['G']++;
		if (toupper(s[i]) == 'P') m['P']++;
		if (toupper(s[i]) == 'L') m['L']++;
		if (toupper(s[i]) == 'T') m['T']++;
	}
	while (m['G'] > 0 || m['P'] > 0 || m['L'] > 0 || m['T'] > 0) {
		if (m['G']-- > 0) printf("G");
		if (m['P']-- > 0) printf("P");
		if (m['L']-- > 0) printf("L");
		if (m['T']-- > 0) printf("T");
	}
	return 0;
}
