#include <iostream>
using namespace std;
string m[4][2] = {
	"can you", "* can",
	"could you", "* could",
	"I", "you",
	"me", "you"
};
int main() {
	int n;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		string s;
		getline(cin,s);
		cout << s << "\nAI: ";
		while (s.length() > 0 && s[0] == ' ') s.erase(s.begin());
		while (s.length() > 0 && s[s.length()-1] == ' ') s.erase(s.end()-1);
		for (int j = 1; j < s.size(); j++)
			if (s[j] == ' ') {
				while (j+1 < s.length() && s[j+1] == ' ') s.erase(j+1, 1);
				if (j+1 < s.length() && isalnum(s[j+1]) == 0) s.erase(j, 1);
			}
		for (auto &c : s) {
			if (c != 'I') c = tolower(c);
			if (c == '?') c = '!';
		}
		for (int j = 0; j < 4; j++) {
			int k = s.find(m[j][0]), l = m[j][0].length();
			while (k != string::npos) {
				if ((k == 0 || !isalnum(s[k-1])) && (k+l == s.size() || !isalnum(s[k+l])))
					s.replace(k, l, m[j][1]);
				k = s.find(m[j][0], k+1);
			}
		}
		for (auto &c : s)
			if (c == '*') c = 'I';
		cout << s << endl;
	}
	return 0;
}
