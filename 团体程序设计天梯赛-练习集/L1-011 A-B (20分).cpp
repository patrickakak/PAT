#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	unordered_map<char, int> m;
	for (int i = 0; i < b.length(); i++) m[b[i]] = 1;
	for (int i = 0; i < a.length(); i++)
		if (m[a[i]] == 0) printf("%c", a[i]);
	return 0;
}
