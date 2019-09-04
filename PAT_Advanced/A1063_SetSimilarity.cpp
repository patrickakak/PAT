/**
 * Sample input:
 * 3
 * 3 99 87 101
 * 4 87 101 5 87
 * 7 99 101 18 5 135 18 99
 * 2
 * 1 2
 * 1 3
 * --------------------
 * Sample output:
 * 50.0%
 * 33.3%
 */
#include <cstdio>
#include <cstring>
#include <set>	// red-black tree
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 51;
set<int> st[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, k, num, index1, index2;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d", &num);
			st[i].insert(num);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &index1, &index2);
		int tot = st[index1].size() + st[index2].size(), cnt = 0;
		set<int>::iterator it = st[index1].begin();
		for ( ; it != st[index1].end(); it++) {
			int x = *it;
			if (x == *(st[index2].find(x)))
				cnt++;
		}
		printf("%.1f%%\n", (double)100*cnt/(tot-cnt));
	}

	return 0;
}


