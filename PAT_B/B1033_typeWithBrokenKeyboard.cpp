/**
 * Sample input:
 * 7+IE.
 * 7_This_is_a_test.
 * -----------------
 * Sample output:
 * _hs_s_a_tst
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>
// #include <windows.h>
using namespace std;

const int maxn = 100100;
bool hashTbl[256];		// true: key is intact
char str[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);

	memset(hashTbl, true, sizeof(hashTbl));
	cin.getline(str, maxn);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		hashTbl[(int)str[i]] = false;
	}
	cin.getline(str, maxn);
	len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a';
			if (hashTbl[low] == true && hashTbl['+'] == true)
				printf("%c", str[i]);
		} else if (hashTbl[(int)str[i]] == true)
			printf("%c", str[i]);
	printf("\n");

	return 0;
}


