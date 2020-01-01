
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/* Only to store the index of names would be better to 
 * take care of large chunk of data */
const int maxc = 2505;
vector<int> v[maxc];
const int maxn = 40010;
char stu[maxn][5];

bool cmp(int a, int b)
{
	return strcmp(stu[a], stu[b]) < 0;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, k, c, courseID;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", stu[i], &c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &courseID);
			v[courseID].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
		printf("%d %d\n", i, v[i].size());
		for (int j = 0; j < (int)v[i].size(); j++)
			printf("%s\n", stu[v[i][j]]);
	}

	return 0;
}

