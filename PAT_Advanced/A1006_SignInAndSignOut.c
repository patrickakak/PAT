/**
 * Sample input:
 * 3
 * CS301111 15:30:28 17:00:10
 * SC3021234 08:00:00 11:25:25
 * CS301133 21:45:00 21:58:40
 * --------------------------
 * Sample output:
 * SC3021234 CS301133
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ID_L 16

typedef struct {
	char id[ID_L];
	int hh, mm, ss;
} time;

time t1, t2, earliest, latest;

void init()
{
	earliest.hh = 24;
	earliest.mm = earliest.ss = 60;
	latest.hh = latest.mm = latest.ss = 0;
}

bool less(time t1, time t2)
{
	if (t1.hh != t2.hh)
		return t1.hh < t2.hh;
	else if (t1.mm != t2.mm)
		return t1.mm < t2.mm;
	else
		return t1.ss < t2.ss;
}

bool more(time t1, time t2)
{
	if (t1.hh != t2.hh)
		return t1.hh > t2.hh;
	else if (t1.mm != t2.mm)
		return t1.mm > t2.mm;
	else
		return t1.ss > t2.ss;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	int M, i;

	init();
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%s %d:%d:%d %d:%d:%d",
				t1.id, &t1.hh, &t1.mm, &t1.ss, &t2.hh, &t2.mm, &t2.ss);
		strcpy(t2.id, t1.id);
		if (more(earliest, t1))
			earliest = t1;
		if (less(latest, t2))
			latest = t2;
	}
	printf("%s %s\n", earliest.id, latest.id);

	return 0;
}

