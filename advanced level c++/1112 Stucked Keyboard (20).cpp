#include <iostream>
#include <vector>
using namespace std;
int main() {
	int k, cnt = 1, ok[256];
	string s, suspect;
	cin >> k >> s;
	char pre = '#';
	s += '#';
	for (int i = 0; i < s.length(); i++)
		if (s[i] == pre) cnt++;
		else {
			if (cnt % k == 0) {
				if (suspect.find(pre) == string::npos) suspect += pre;
			} else ok[pre] = 1;
			pre = s[i];
			cnt = 1;
		}
	for (int i = 0; i < suspect.length(); i++)
		if (ok[suspect[i]] == 1) suspect.erase(i);
	cout << suspect << endl;
	for (int i = 0; i < s.length()-1; i++) {
		printf("%c", s[i]);
		if (suspect.find(s[i]) != string::npos) i += k-1;
	}
	return 0;
}
