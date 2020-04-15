#include <iostream>
using namespace std;
pair<string, string> p[] = {{"can you","* can"},{"could you","* could"},{"I","you"},{"me","you"}};
int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		cout << s << "\nAI: ";
		while (s.length() > 0 && s[0] == ' ') s.erase(s.begin());
		while (s.length() > 0 && s[s.length()-1] == ' ') s.erase(s.end()-1);
		for (int j = 0; j < s.size(); j++)
			if (s[j] == ' ') {
				while (j+1 < s.length() && s[j+1] == ' ') s.erase(j+1, 1);
				if (j+1 < s.length() && ispunct(s[j+1])) s.erase(j, 1);
			}
		for (auto &c : s) {
			if (c != 'I') c = tolower(c);
			if (c == '?') c = '!';
		}
		for (int j = 0; j < 4; j++) {
			int k = s.find(p[j].first), l = p[j].first.length();
			while (k != string::npos) {
				if ((k == 0 || !isalnum(s[k-1])) && (k+l == s.size() || !isalnum(s[k+l])))
					s.replace(k, l, p[j].second);
				k = s.find(p[j].first, k+1);
			}
		}
		for (auto &c : s) {
			if (c == '*') c = 'I';
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
