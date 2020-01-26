#include <iostream>
using namespace std;
int h[256];
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.length(); i++)
		h[s2[i]]++;
	for (int i = 0; i < s1.length(); i++) {
		if (h[s1[i]] > 0) continue;
		printf("%c", s1[i]);
	}
	return 0;
}
