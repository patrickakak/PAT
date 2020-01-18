/**
 * Sample input1:
 * 3 1
 * 000007 James 85
 * 000010 Amy 90
 * 000001 Zoe 60
 * Sample output1:
 * 000001 Zoe 60
 * 000007 James 85
 * 000010 Amy 90
 * ---------------
 * Sample input2:
 * 4 2
 * 000007 James 85
 * 000010 Amy 90
 * 000001 Zoe 60
 * 000002 James 98
 * Sample output2:
 * 000010 Amy 90
 * 000002 James 98
 * 000007 James 85
 * 000001 Zoe 60
 * --------------
 * Sample input3:
 * 4 3
 * 000007 James 85
 * 000010 Amy 90
 * 000001 Zoe 60
 * 000002 James 90
 * Sample output3:
 * 000001 Zoe 60
 * 000007 James 85
 * 000002 James 90
 * 000010 Amy 90
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
//#include <windows.h>
using namespace std;

#define maxn 100010
struct Stu {
	int id;			// 1 incre
	char name[10];	// 2 non-desc
	int grade;		// 3 non-decre
} stu[maxn];

int flag;
bool cmp(Stu a, Stu b)
{
	int x;
	switch (flag) {
	case 1:
		return a.id < b.id;
	case 2:
		x = strcmp(a.name, b.name);
		if (x != 0) return x<0;
		else return a.id < b.id;
	default:
		if (a.grade != b.grade) return a.grade < b.grade;
		else return a.id < b.id;
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].grade);
	flag = C;
	sort(stu, stu+N, cmp);
	for (int i = 0; i < N; i++)
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);

	return 0;
}


