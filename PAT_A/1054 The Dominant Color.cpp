/**
 * Sample input:
 * 5 3
 * 0 0 255 16777215 24
 * 24 24 0 0 24
 * 24 0 24 24 24
 * ------------------
 * Sample output:
 * 24
 */
#include <cstdio>
#include <map>  // red-black tree
using namespace std;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int m, n, num;
	map<int, int> mp;

	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &num);
			if (mp.find(num) != mp.end())
				mp[num]++;
			else
				mp[num] = 1;
		}
	int k = 0, MAX = 0;
	for (map<int, int>::iterator it=mp.begin(); it != mp.end(); it++)
		if (it->second > MAX) {
			k = it->first;
			MAX = it->second;
		}
	printf("%d\n", k);

	return 0;
}


