/**
 * Sample input1:
 * 4
 * Tom CS000001 59
 * Joe Math990112 89
 * Mike CS991301 100
 * Mary EE990830 95
 * 60 100
 * Sample output1:
 * Mike CS991301
 * Mary EE990830
 * Joe Math990112
 * -----------------
 * Sample input2:
 * 2
 * Jean AA980920 60
 * Ann CS01 80
 * 90 95
 * Sample output2:
 * NONE
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

#define maxn 100010
struct Stu {
	char name[15];
	char id[15];
	int grade;
} stu[maxn];

bool cmp(Stu a, Stu b)
{
	return a.grade > b.grade;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);

	sort(stu, stu+n, cmp);
	int low, high, cnt = 0;
	scanf("%d%d", &low, &high);
	for (int i = 0; i < n; i++)
		if (stu[i].grade >= low && stu[i].grade <= high) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			cnt++;
		}
	if (cnt == 0)
		printf("NONE\n");

	return 0;
}


