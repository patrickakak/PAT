#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int len = s.length(), res = 0, pcnt = 0, tcnt = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == 'T')
			tcnt++;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'P') pcnt++;
		if (s[i] == 'T') tcnt--;
		if (s[i] == 'A') res = (res + (pcnt * tcnt) % 1000000007) % 1000000007;
	}
	cout << res;
	return 0;
}
