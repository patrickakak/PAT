#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
void query(unordered_map<string, set<int>> &m, string s) {
	if (m.find(s) == m.end()) printf("Not Found\n");
	else for (auto it : m[s]) printf("%07d\n", it);
}
int main() {
	int n, id, m, inx;
	scanf("%d\n", &n);
	string s;
	unordered_map<string, set<int>> ttl, au, kw, pub, yr;
	while (n--) {
		scanf("%d\n", &id);
		getline(cin, s);
		ttl[s].insert(id);
		getline(cin, s);
		au[s].insert(id);
		while (1) {
			cin >> s;
			kw[s].insert(id);
			if (getchar() == '\n') break;
		}
		getline(cin, s);
		pub[s].insert(id);
		getline(cin, s);
		yr[s].insert(id);
	}
	scanf("%d\n", &m);
	while (m--) {
		scanf("%d: ", &inx);
		getline(cin, s);
		printf("%d: %s\n", inx, s.c_str());
		switch (inx) {
		case 1: query(ttl, s); break;
		case 2: query(au, s);  break;
		case 3: query(kw, s);  break;
		case 4: query(pub, s); break;
		case 5: query(yr, s);  break;
		}
	}
	return 0;
}
