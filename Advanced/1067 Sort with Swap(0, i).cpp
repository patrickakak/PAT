/**
 * Sample input:
 * 10
 * 3 5 7 2 6 4 9 0 8 1
 * --------------------
 * Sample output:
 * 9
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100010
int pos[maxn];

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n, num, ok = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;
		if (num == i)
			ok++;
	}
	int k = 1, cnt=0;
	while (ok < n) {
		if (pos[0] == 0)
			for (; k < n; k++)
				if (pos[k] != k){
					swap(pos[k], pos[0]);
					cnt++;
					ok--;
					break;
				}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			ok++;
			cnt++;
		}
		ok++;	// plus 0 is in position
	}
	printf("%d\n", cnt);
	return 0;
}


