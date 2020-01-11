/**
 * Sample input:
 * This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
 * -----------------
 * Sample output:
 * e 7
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define maxn 1010
int hashTbl[256] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);

	char str[maxn];
	cin.get(str, maxn);
	int len = strlen(str);
	int maxTime = -1, t;
	for (int i = 0; i < len; i++) {
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
		if (isalpha(str[i])) {
			t = ++hashTbl[(int)str[i]];
			maxTime = max(maxTime, t);
		}
	}

	for (int i = 0 ; i < 256; i++) {
		t = hashTbl[i];
		if (t == maxTime) {
			printf("%c %d\n", (char)i, maxTime);
			break;
		}
	}

	return 0;
}


