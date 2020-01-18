
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	// freopen("tst.txt", "r", stdin);
	int m, n, tmp;
	map<int, int> mp;

	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			if (mp.find(tmp) != mp.end()) mp[tmp]++;
			else mp[tmp] = 1;
		}
	int k, Max = 0;
	for (map<int,int>::iterator it=mp.begin(); it != mp.end(); it++)
		if (Max < it->second) {
			Max = it->second;
			k = it->first;
		}
	printf("%d", k);

	return 0;
}


