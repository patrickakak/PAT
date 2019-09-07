/**
 * Sample input:
 * 23 13
 * 21 1 23
 * 01 4 03 02 04 05
 * 03 3 06 07 08
 * 06 2 12 13
 * 13 1 21
 * 08 2 15 16
 * 02 2 09 10
 * 11 2 19 20
 * 17 1 22
 * 05 1 11
 * 07 1 14
 * 09 1 17
 * 10 1 18
 * ----------------
 * Sample output:
 * 9 4
 */
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 110;
vector<int> node[MAXN];
int hashTbl[MAXN] = {0};

void DFS(int index, int level)
{
	hashTbl[level]++;
	for (int i = 0; i < (int)node[index].size(); i++)
		DFS(node[index][i], level+1);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, parent, k, child;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &parent, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[parent].push_back(child);
		}
	}
	DFS(1, 1);
	int maxLevel = -1, maxValue = 0;
	for (int i = 1; i < MAXN; i++)
		if (hashTbl[i] > maxValue) {
			maxValue = hashTbl[i];
			maxLevel = i;
		}
	printf("%d %d\n", maxValue, maxLevel);

	return 0;
}



