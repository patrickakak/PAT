/**
 * Sample input:
 * 6
 * 3 5 6 7 8 11
 * -------------
 * Sample output:
 * 7 6
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 10010
bool hashTbl[maxn] = {false};
int a[110], key[110], cnt = 0;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		n = a[i];
		while (n != 1) {
			if (n % 2 == 1)
				n = (3*n + 1)/2;
			else
				n /= 2;
			hashTbl[n] = true;
		}
	}
	for (int i = 0; i < k; i++)
		if (hashTbl[a[i]] == false)
			key[cnt++] = a[i];
	sort(key, key+cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		if (i > 0) printf(" ");
		printf("%d", key[i]);
	}

	return 0;
}


