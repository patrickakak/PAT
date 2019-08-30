/**
 * Sample input1:
 * ppRYYGrrYBR2258
 * YrR8RrY
 * Sample output1:
 * Yes 8
 * ---------------
 * Sample input2:
 * ppRYYGrrYB225
 * YrR8RrY
 * Sample output2:
 * No 2
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
	int len1, len2, miss = 0;

	cin.getline(str, maxn);
	len1 = strlen(str);
	for (int i = 0; i < len1; i++)
		hashTbl[(int)str[i]]++;

	cin.get(str, maxn);
	len2 = strlen(str);
	for (int i = 0; i < len2; i++)
		if (hashTbl[(int)str[i]] > 0)
			hashTbl[(int)str[i]]--;
		else
			miss++;

	if (miss == 0)
		printf("Yes %d\n", len1 - len2);
	else
		printf("No %d\n", miss);

	return 0;
}


