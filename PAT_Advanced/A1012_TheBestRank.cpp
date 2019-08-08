/**
 * Sample input:
 * 5 6
 * 310101 98 85 88
 * 310102 70 95 88
 * 310103 82 87 94
 * 310104 91 91 91
 * 310105 85 90 90
 * 310101
 * 310102
 * 310103
 * 310104
 * 310105
 * 999999
 * --------------
 * Sample output:
 * 1 C
 * 1 M
 * 1 E
 * 1 A
 * 3 A
 * N/A
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
	int id;
	int grade[4];
} stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank[1000000][4];
int now;

bool cmp(Student a, Student b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &stu[i].id, 
				&stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3;
	}
	for (now = 0; now < 4; now++) {
		sort(stu, stu+N, cmp);
		Rank[stu[0].id][now] = 1;
		for (int i = 1; i < N; i++)
			if (stu[i].grade[now] == stu[i-1].grade[now])
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			else
				Rank[stu[i].id][now] = i+1;
	}
	int query;
	for (int i = 0; i < M; i++) {
		scanf("%d", &query);
		if (Rank[query][0] == 0)
			printf("N/A\n");
		else {
			int k = 0;
			for (int j = 1; j < 4; j++)
				if (Rank[query][j] < Rank[query][k])
					k = j;
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}

	return 0;
}

