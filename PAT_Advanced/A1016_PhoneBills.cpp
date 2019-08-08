/**
 * Sample input:
 * 10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
 * 10
 * CYLL 01:01:06:01 on-line
 * CYLL 01:28:16:05 off-line
 * CYJJ 01:01:07:00 off-line
 * CYLL 01:01:08:03 off-line
 * CYJJ 01:01:05:59 on-line
 * aaa 01:01:01:03 on-line
 * aaa 01:02:00:01 on-line
 * CYLL 01:28:15:41 on-line
 * aaa 01:05:02:24 on-line
 * aaa 01:04:23:59 off-line
 * ------------------------
 * Sample output:
 * CYJJ 01
 * 01:05:59 01:07:00 61 $12.10
 * Total amount: $12.10
 * CYLL 01
 * 01:06:01 01:08:03 122 $24.40
 * 28:15:41 28:16:05 24 $3.85
 * Total amount: $28.25
 * aaa 01
 * 02:00:01 04:23:59 4318 $638.80
 * Total amount: $638.80
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int toll[25];
struct Record {
	char name[25];
	int month, dd, hh, mm;
	bool status;
} rec[maxn], tmp;

bool cmp(Record a, Record b)
{
	int x = strcmp(a.name, b.name);
	if (x != 0) return x < 0;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}

void get_ans(int on, int off, int &time, int &charge)
{
	tmp = rec[on];
	while (tmp.dd < rec[off].dd 
			|| tmp.hh < rec[off].hh || tmp.mm < rec[off].mm) {
		time++;
		charge += toll[tmp.hh];
		tmp.mm++;
		if (tmp.mm >= 60) {
			tmp.mm = 0;
			tmp.hh++;
		}
		if (tmp.hh >= 24) {
			tmp.hh = 0;
			tmp.dd++;
		}
	}
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	for (int i = 0; i < 24; i++)
		scanf("%d", &toll[i]);
	int n;
	scanf("%d", &n);
	char line[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", rec[i].name);
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
		scanf("%s", line);
		if (strcmp(line, "on-line") == 0)
			rec[i].status = true;
		else
			rec[i].status = false;
	}
	sort(rec, rec+n, cmp);
	int on = 0, off, next;
	while (on < n) {
		int needPrint = 0;
		next = on;
		while (next < n && strcmp(rec[next].name, rec[on].name) == 0) {
			if (needPrint == 0 && rec[next].status == true)
				needPrint = 1;
			else if (needPrint == 1 && rec[next].status == false)
				needPrint = 2;
			next++;
		}
		if (needPrint < 2) {
			on = next;
			continue;
		}
		int AllMoney = 0;
		printf("%s %02d\n", rec[on].name, rec[on].month);
		while (on < next) {
			while (on < next-1 &&
					!(rec[on].status==true && rec[on+1].status==false))
				on++;
			off = on + 1;
			if (off == next) {
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
			printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
			int time = 0, money = 0;
			get_ans(on, off, time, money);
			AllMoney += money;
			printf("%d $%.2f\n", time, money/100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", AllMoney/100.0);
	}

	return 0;
}

