/**
 * Sample input:
 * 11 6 3
 * 2 1 2 2 2 3
 * 100 100 0 1 2
 * 60 60 2 3 5
 * 100 90 0 3 4
 * 90 100 1 2 0
 * 90 90 5 1 3
 * 80 90 1 0 2
 * 80 80 0 1 2
 * 80 80 0 1 2
 * 80 70 1 3 2
 * 70 80 1 2 3
 * 100 100 0 2 4
 * ---------------
 * Sample output:
 * 0 10
 * 3
 * 5 6 7
 * 2 8
 *
 * 1 4
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>
// #include <windows.h>
using namespace std;

#define maxstu 40010
struct Stu {
	int id;
	int prefer[6];		// preferred school number
	int GE, GI, sum;	// exam/interview grade
	int r;				// rank
} stu[maxstu];

#define maxsch 110
struct School {
	int quota;
	int last;			// last admitted stu id
	int num;			// student num
	int ids[maxstu];	// student ids
} sch[maxsch];

bool cmp(Stu a, Stu b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	else return a.GE > b.GE;
}

bool cmpId(int a, int b)
{
	return stu[a].id < stu[b].id;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", &sch[i].quota);
		sch[i].last = -1;
	}
	for (int i = 0; i < n; i++) {
		stu[i].id = i;
		scanf("%d%d", &stu[i].GE, &stu[i].GI);
		stu[i].sum = stu[i].GE + stu[i].GI;
		for (int j = 0; j < k; j++)
			scanf("%d", &stu[i].prefer[j]);
	}
	sort(stu, stu+n, cmp);
	stu[0].r = 1;
	for (int i = 1; i<n; i++)
		if (stu[i].sum == stu[i-1].sum && stu[i].GE == stu[i-1].GE)
			stu[i].r = stu[i-1].r;
		else
			stu[i].r = i+1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			int sid = stu[i].prefer[j];
			int num = sch[sid].num;
			int last = sch[sid].last;
			if (num < sch[sid].quota || (last!=-1 && stu[i].r==stu[last].r)) {
				sch[sid].ids[num] = i;
				sch[sid].num++;
				sch[sid].last=i;
				break;
			}
		}
	for (int i = 0; i < m; i++) {
		if (sch[i].num > 0) {
			sort(sch[i].ids, sch[i].ids+sch[i].num, cmpId);
			for (int j = 0; j < sch[i].num; j++) {
				printf("%d", stu[sch[i].ids[j]].id);
				if (j < sch[i].num - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}


