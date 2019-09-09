/**
 * Sample input:
 * 2
 * 5
 * 1234567890001 95
 * 1234567890005 100
 * 1234567890003 95
 * 1234567890002 77
 * 1234567890004 85
 * 4
 * 1234567890013 65
 * 1234567890011 25
 * 1234567890014 100
 * 1234567890012 85
 * ----------------
 * Sample output:
 * 9
 * 1234567890005 1 1 1
 * 1234567890014 1 2 1
 * 1234567890001 3 1 2
 * 1234567890003 3 1 2
 * 1234567890004 5 1 4
 * 1234567890012 5 2 2
 * 1234567890002 7 1 5
 * 1234567890013 8 2 3
 * 1234567890011 9 2 4
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu {
	char id[20];
	int grade;
	int loc;
	int r;
} stu[30010];

bool cmp(Stu a, Stu b)
{
	if (a.grade != b.grade) return a.grade > b.grade;
	else return strcmp(a.id, b.id) < 0;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int N, K, num = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &K);
		for (int j = 0 + num; j < K + num; j++) {
			scanf("%s%d", stu[j].id, &stu[j].grade);
			stu[j].loc = i + 1;
		}
		sort(stu+num, stu+num+K, cmp);
		stu[num].r = 1;
		for (int j = 1 + num; j < K + num; j++)
			if (stu[j].grade == stu[j-1].grade)
				stu[j].r = stu[j-1].r;
			else
				stu[j].r = j + 1 - num;
		num += K;
	}
	sort(stu, stu+num, cmp);
	printf("%d\n", num);
	int r = 1;
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].grade != stu[i-1].grade)
			r = i + 1;
		printf("%s %d %d %d\n", stu[i].id, r, stu[i].loc, stu[i].r);
	}

	return 0;
}


