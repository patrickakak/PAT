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

struct Student {
	char id[15];
	int score;
	int loc_no;		// location number
	int loc_r;		// local rank
} stu[30010];

bool cmp(Student a, Student b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0;
}

int main()
{
	//freopen("tst.txt", "r", stdin);

	int n, k, num = 0;

	scanf("%d", &n);
	for (int i=1; i <= n; i++) {
		scanf("%d", &k);
		for (int j=0; j < k; j++) {
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].loc_no = i;
			num++;
		}
		sort(stu+num-k, stu+num, cmp);
		stu[num-k].loc_r = 1;
		for (int j=num-k+1; j < num; j++)
			if (stu[j].score == stu[j-1].score)
				stu[j].loc_r = stu[j-1].loc_r;
			else
				stu[j].loc_r = j+1-(num-k);
	}
	printf("%d\n", num);
	sort(stu, stu+num, cmp);

	int r = 1;
	for (int i=0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i-1].score)
			r = i + 1;
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].loc_no, stu[i].loc_r);
	}

	return 0;
}

