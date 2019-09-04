/**
 * Sample input:
 * 10 5
 * ZOE1 2 4 5
 * ANN0 3 5 2 1
 * BOB5 5 3 4 2 1 5
 * JOE4 1 2
 * JAY9 4 1 2 5 4
 * FRA8 3 4 2 5
 * DON2 2 4 5
 * AMY7 1 5
 * KAT3 3 5 4 2
 * LOR6 4 2 4 1 5
 * ----------------
 * Sample output:
 * 1 4
 * ANN0
 * BOB5
 * JAY9
 * LOR6
 * 2 7
 * ANN0
 * BOB5
 * FRA8
 * JAY9
 * JOE4
 * KAT3
 * LOR6
 * 3 1
 * BOB5
 * 4 7
 * BOB5
 * DON2
 * FRA8
 * JAY9
 * KAT3
 * LOR6
 * ZOE1
 * 5 9
 * AMY7
 * ANN0
 * BOB5
 * DON2
 * FRA8
 * JAY9
 * KAT3
 * LOR6
 * ZOE1
 */
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


