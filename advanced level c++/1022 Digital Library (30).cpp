#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<string, set<int>> ttl, au, key, pub, yr;
void query(unordered_map<string, set<int>> &m, string &s) {
	if (m.find(s) == m.end()) printf("Not Found\n");
	else for (auto it : m[s]) printf("%07d\n", it);
}
int main() {
	int n, m, num, id;
	string tt, ta, tk, tp, ty, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &id);
		getline(cin, tt);
		ttl[tt].insert(id);
		getline(cin, ta);
		au[ta].insert(id);
		while (cin >> tk) {
			key[tk].insert(id);
			char c = getchar();
			if (c == '\n') break;
		}
		getline(cin, tp);
		pub[tp].insert(id);
		getline(cin, ty);
		yr[ty].insert(id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &num);
		getline(cin, tmp);
		cout << num << ": " << tmp << endl;
		switch (num) {
		case 1: query(ttl, tmp); break;
		case 2: query(au, tmp);  break;
		case 3: query(key, tmp); break;
		case 4: query(pub, tmp); break;
		case 5: query(yr, tmp);  break;
		}
	}
	return 0;
}
