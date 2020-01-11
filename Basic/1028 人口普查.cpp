/**
 * Sample input:
 * 5
 * John 2001/05/12
 * Tom 1814/09/06
 * Ann 2121/01/30
 * James 1814/09/05
 * Steve 1967/11/20
 * ----------------
 * Sample output:
 * 3 Tom John
 */
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	char name[10];
	int yy, mm, dd;
} person;

person oldest, youngest, left, right, tmp;

bool LessEqu(person a, person b)
{
	if (a.yy != b.yy)
		return a.yy <= b.yy;
	else if (a.mm != b.mm)
		return a.mm <= b.mm;
	else
		return a.dd <= b.dd;
}

bool MoreEqu(person a, person b)
{
	if (a.yy != b.yy)
		return a.yy >= b.yy;
	else if (a.mm != b.mm)
		return a.mm >= b.mm;
	else
		return a.dd >= b.dd;
}

void init()
{
	youngest.yy = left.yy = 1814;
	oldest.yy = right.yy = 2014;
	youngest.mm = oldest.mm = left.mm = right.mm = 9;
	youngest.dd = oldest.dd = left.dd = right.dd = 6;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	init();
	int i, n, num = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", tmp.name, &tmp.yy, &tmp.mm, &tmp.dd);
		if (MoreEqu(tmp, left) && LessEqu(tmp, right)) {
			num++;
			if (LessEqu(tmp, oldest))
				oldest = tmp;
			if (MoreEqu(tmp, youngest))
				youngest = tmp;
		}
	}
	if (num == 0)
		printf("0\n");
	else
		printf("%d %s %s\n", num, oldest.name, youngest.name);

	return 0;
}

