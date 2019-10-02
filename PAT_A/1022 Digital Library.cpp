/**
 * Sample input:
 * 3
 * 1111111
 * The Testing Book
 * Yue Chen
 * test code debug sort keywords
 * ZUCS Print
 * 2011
 * 3333333
 * Another Testing Book
 * Yue Chen
 * test code sort keywords
 * ZUCS Print2
 * 2012
 * 2222222
 * The Testing Book
 * CYLL
 * keywords debug book
 * ZUCS Print2
 * 2011
 * 6
 * 1: The Testing Book
 * 2: Yue Chen
 * 3: keywords
 * 4: ZUCS Print
 * 5: 2011
 * 3: blablabla
 * ---------------------
 * Sample output:
 * 1: The Testing Book
 * 1111111
 * 2222222
 * 2: Yue Chen
 * 1111111
 * 3333333
 * 3: keywords
 * 1111111
 * 2222222
 * 3333333
 * 4: ZUCS Print
 * 1111111
 * 5: 2011
 * 1111111
 * 2222222
 * 3: blablabla
 * Not Found
 */
#include <cstdio>
#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;

map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

void query(map<string, set<int> > &mp, string &str)
{
	if (mp.find(str) == mp.end()) printf("Not Found\n");
	else
		for (set<int>::iterator it=mp[str].begin(); it != mp[str].end(); it++)
			printf("%07d\n", *it);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, id, type;
	string title, author, key, pub, year;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c == '\n') break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}
	string tmp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &type);
		getline(cin, tmp);
		cout << type << ": " << tmp << endl;
		switch (type) {
		case 1:
			query(mpTitle, tmp);
			break;
		case 2:
			query(mpAuthor, tmp);
			break;
		case 3:
			query(mpKey, tmp);
			break;
		case 4:
			query(mpPub, tmp);
			break;
		case 5:
			query(mpYear, tmp);
			break;
		}
	}

	return 0;
}


