
#include <map>
#include <set>
#include <iostream>
using namespace std;

map<string, set<int>> title, author, key, pub, year;
void query(map<string, set<int>> &m, string &s)
{
	if (m.find(s) == m.end()) cout << "Not Found\n";
	else
		for (auto it = m[s].begin(); it != m[s].end(); it++)
			printf("%07d\n", *it);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, num, id;
	string tt, ta, tk, tp, ty, tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &id);
		getline(cin, tt);
		title[tt].insert(id);
		getline(cin, ta);
		author[ta].insert(id);
		while (cin >> tk) {
			key[tk].insert(id);
			char c = getchar();
			if (c == '\n') break;
		}
		getline(cin, tp);
		pub[tp].insert(id);
		getline(cin, ty);
		year[ty].insert(id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &num);
		getline(cin, tmp);
		cout << num << ": " << tmp << endl;
		switch (num) {
		case 1: query(title, tmp);  break;
		case 2: query(author, tmp); break;
		case 3: query(key, tmp);    break;
		case 4: query(pub, tmp);    break;
		case 5: query(year, tmp);   break;
		}
	}

	return 0;
}


