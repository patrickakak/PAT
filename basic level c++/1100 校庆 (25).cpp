#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool cmp(string &a, string &b) {
	return a.substr(6, 8) < b.substr(6, 8);
}
int main() {
	int n, m;
	cin >> n;
	unordered_map<string, bool> mp;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s] = true;
	}
	cin >> m;
	vector<string> alumna, attendee;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (mp[s] == true) alumna.push_back(s);
		attendee.push_back(s);
	}
	printf("%d\n", alumna.size());
	if (alumna.size() != 0) {
		sort(alumna.begin(), alumna.end(), cmp);
		printf("%s", alumna[0].c_str());
	} else {
		sort(attendee.begin(), attendee.end(), cmp);
		printf("%s", attendee[0].c_str());
	}
	return 0;
}
