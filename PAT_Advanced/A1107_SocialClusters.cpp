/**
 * Sample input:
 * 8
 * 3: 2 7 10
 * 1: 4
 * 2: 5 3
 * 1: 4
 * 1: 3
 * 1: 4
 * 4: 6 8 1 5
 * 1: 4
 * i--------------
 * Sample output:
 * 3
 * 4 3 1
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int S[maxn], hobby[maxn];

void init()
{
	for (int i = 0; i < maxn; i++) {
		hobby[i] = -1;
		S[i] = -1;
	}
}

int Find(int x)
{
	if (S[x] < 0) return x;
	else return S[x] = Find(S[x]);
}

void Union(int Root1, int Root2)
{
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	} else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, k, h, num = 0;

	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &h);
			if (hobby[h] == -1) hobby[h] = i;
			else Union(Find(i), Find(hobby[h]));
		}
	}
	for (int i = 1; i <= n; i++)
		if (S[i] < 0) num++;
	sort(S + 1, S + n + 1);
	printf("%d\n", num);
	for (int i = 1; i <= num; i++) {
		printf("%d", -S[i]);
		if (i < num) printf(" ");
	}

	return 0;
}



