/**
 * Sample input:
 * 7_This_is_a_test
 * _hs_s_a_es
 * ----------------
 * Sample output:
 * 7TI
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

// 0~9 A~Z _
bool hashTbl[37] = {false}; // 10+26+1=37
// lowercase to uppercase
void l2u(char s[], int len)
{
	for (int i =0; i<len; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	char s1[100], s2[100];
	int len1, len2, i = 0, j = 0, k;

	scanf("%s%s", s1, s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	l2u(s1, len1);
	l2u(s2, len2);
	while (i < len1)
		if (s1[i] != s2[j]) {
			if (s1[i] >= 'A' && s1[i] <= 'Z') k = s1[i] - 'A' + 10;
			else if (s1[i] >= '0' && s1[i] <= '9') k = s1[i] - '0';
			else k = 36;
			if (hashTbl[k] == false) {
				printf("%c", s1[i]);
				hashTbl[k] = true;
			}
			i++;
		} else {
			i++;
			j++;
		}

	return 0;
}


