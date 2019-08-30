/**
 * Sample input1:
 * 7 5 31 5 88 67 88 17
 * Sample outupt1:
 * 31
 * ------------------
 * Sample intput2:
 * 5 888 666 666 888 888
 * Sample output2:
 * None
 */
#include <cstdio>

#define maxn 100010
int hashTbl[maxn] = {0};
int order[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		hashTbl[num]++;
		order[num] = i;
	}
	int Min = maxn, k = -1;
	for (int i = 0; i < maxn; i++)
		if (hashTbl[i] == 1 && order[i] < Min) {
			k = i;
			Min = order[i];
		}
	if (k == -1) printf("None\n");
	else printf("%d\n", k);

	return 0;
}


