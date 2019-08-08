/**
 * Sample input:
 * 14 60 80
 * 10000001 64 90
 * 10000002 90 60
 * 10000011 85 80
 * 10000003 85 80
 * 10000004 80 85
 * 10000005 82 77
 * 10000006 83 76
 * 10000007 90 78
 * 10000008 75 79
 * 10000009 59 90
 * 10000010 88 45
 * 10000012 80 100
 * 10000013 90 99
 * 10000014 66 60
 * ---------------
 * Sample output:
 * 12
 * 10000013 90 99
 * 10000012 80 100
 * 10000003 85 80
 * 10000011 85 80
 * 10000004 80 85
 * 10000007 90 78
 * 10000006 83 76
 * 10000005 82 77
 * 10000002 90 60
 * 10000014 66 60
 * 10000008 75 79
 * 10000001 64 90
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define Max_N 100010
struct Student {
	char id[10];
	int de, cai, sum;
	int flag;	// student type
} stu[Max_N];

bool cmp(Student a, Student b)
{
	if (a.flag != b.flag) return a.flag < b.flag;
	else if (a.sum != b.sum) return a.sum > b.sum;
	else if (a.de != b.de) return a.de > b.de;
	else return strcmp(a.id, b.id) < 0;
}


int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, M, L, H;

	scanf("%d %d %d", &N, &L, &H);
	M = N;
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if (stu[i].de < L || stu[i].cai < L) {
			stu[i].flag = 5;
			M--;
		} else if (stu[i].de >= H && stu[i].cai >= H)
			stu[i].flag = 1;
		else if (stu[i].de >= H)
			stu[i].flag = 2;
		else if (stu[i].de >= stu[i].cai)
			stu[i].flag = 3;
		else
			stu[i].flag = 4;
	}
	sort(stu, stu+N, cmp);
	printf("%d\n", M);
	for (int i = 0; i < M; i++)
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);

	return 0;
}


