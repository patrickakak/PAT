#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n, maxn = 0, cnt = 0;
	cin >> n;
	string a, b, str;
	unordered_map<string, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m[a]++, m[b]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > maxn) {
			maxn = it->second;
			str = it->first;
			cnt = 1;
		} else if (it->second == maxn) {
			cnt++;
			if (it->first < str) str = it->first;
		}
	printf("%s %d", str.c_str(), m[str]);
	if (cnt > 1) printf(" %d", cnt);
	return 0;
}
