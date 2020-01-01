
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2501;
vector<string> courseStu[N];
/* Only to store the index of names would be better to 
 * take care of large chunk of data */
// char name[maxn][5];
// vector<int> course[maxc];

int main()
{
	// freopen("tst.txt", "r", stdin);
	char name[5];
	int n, k, num, courseID;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name, &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &courseID);
			courseStu[courseID].push_back(name);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, courseStu[i].size());
		sort(courseStu[i].begin(), courseStu[i].end());
		for (int j = 0; j < (int)courseStu[i].size(); j++)
			printf("%s\n", courseStu[i][j].c_str());
	}

	return 0;
}


