#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int len = s.length(), a[26] = {0};
	for (int i = 0; i < len; i++) {
		s[i] = tolower(s[i]);
		if (isalpha(s[i]))
			a[s[i] - 'a']++;
	}
	int p = max_element(a, a + 26) - a;
	printf("%c %d", p + 'a', a[p]);
	return 0;
}
