#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 0, pcnt = 0, tcnt = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'T') tcnt++;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P') pcnt++;
		if (s[i] == 'T') tcnt--;
		if (s[i] == 'A') ans = (ans + (pcnt * tcnt) % 1000000007) % 1000000007;
	}
	printf("%d", ans);
	return 0;
}
