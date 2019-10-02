/**
 * Sample input:
 * redlesPayBestPATTopTeePHPereatitAPPT
 * ------------------------
 * Sample output:
 * PATestPATestPTetPTePePee
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define maxn 10010
char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTbl[6] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);

	char str[maxn];
	cin.getline(str, maxn);
	int len = strlen(str);
	int sum = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < 6; j++)
			if (str[i] == dict[j]) {
				hashTbl[j]++;
				sum++;
			}
	while (sum > 0)
		for (int i = 0; i < 6; i++)
			if (hashTbl[i] > 0) {
				printf("%c", dict[i]);
				hashTbl[i]--;
				sum--;
			}

	return 0;
}


