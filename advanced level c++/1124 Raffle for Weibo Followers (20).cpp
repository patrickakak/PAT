#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int m, n, s, cnt = 0;
	cin >> m >> n >> s;
	string str;
	unordered_map<string, int> mp;
	for (int i = 1; i <= m; i++) {
		cin >> str;
		if (mp[str] == 1) s += 1;
		if (i == s && mp[str] == 0) {
			mp[str] = 1;
			printf("%s\n", str.c_str());
			cnt++;
			s += n;
		}
	}
	if (cnt == 0) cout << "Keep going...";
	return 0;
}
