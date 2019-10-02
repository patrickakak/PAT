/**
 * Sample input:
 * They are students.
 * aeiou
 * -----------------
 * Sample output:
 * Thy r stdnts.
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define maxn 10010
bool hashTbl[256] = {false};

int main()
{
	// freopen("tst.txt", "r", stdin);
	char s1[maxn], s2[maxn];

	// scanf() works bad when read lots of chars
	cin.getline(s1, maxn);
	cin.getline(s2, maxn);
	for (int i = 0; i < (int)strlen(s2); i++)
		hashTbl[(int)s2[i]] = true;

	for (int i = 0; i < (int)strlen(s1); i++)
		if (hashTbl[(int)s1[i]] == false)
			printf("%c", s1[i]);
	printf("\n");

	return 0;
}


