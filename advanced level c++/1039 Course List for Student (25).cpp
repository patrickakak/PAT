#include <iostream>
#include <set>
using namespace std;
set<int> st[26*26*26*10+1];
int getid(string s) {
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = id * 26 + (s[i] - 'A');
	return id * 10 + (s[3] - '0');
}
int main() {
	int n, k, cid, num;
	cin >> n >> k;
	string s;
	while (k--) {
		cin >> cid >> num;
		for (int i = 0; i < num; i++) {
			cin >> s;
			st[getid(s)].insert(cid);
		}
	}
	while (n--) {
		cin >> s;
		int id = getid(s);
		printf("%s %d", s.c_str(), st[id].size());
		for (auto it=st[id].begin(); it!=st[id].end(); it++)
			printf(" %d", *it);
		printf("\n");
	}
	return 0;
}
