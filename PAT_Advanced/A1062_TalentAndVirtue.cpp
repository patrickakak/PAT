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

#define maxn 100100
struct Stu {
	int id;
	int v;	// virtue
	int t;	// talent
	int r;	// rank
	int tol;
} stu[maxn];

bool cmp(Stu a, Stu b)
{
	if (a.r != b.r) return a.r < b.r;
	else if (a.tol != b.tol) return a.tol>b.tol;
	else if (a.v != b.v) return a.v > b.v;
	else return a.id < b.id;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	Stu tmp;
	int num = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &tmp.id, &tmp.v, &tmp.t);
		if (tmp.t >= L && tmp.v >= L) {
			tmp.tol=tmp.v+tmp.t;
			if (tmp.t >= H && tmp.v >= H)
				tmp.r = 1;
			else if (tmp.v >= H && tmp.t < H)
				tmp.r = 2;
			else if (tmp.v < H && tmp.t < H && tmp.v >= tmp.t)
				tmp.r = 3;
			else
				tmp.r = 4;
			stu[num++] = tmp;
		}
	}
	sort(stu, stu+num, cmp);
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
		printf("%d %d %d\n", stu[i].id, stu[i].v, stu[i].t);

	return 0;
}


