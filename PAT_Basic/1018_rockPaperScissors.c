/**
 * Sample Input:
 * 10
 * C J
 * J B
 * C B
 * B B
 * B C
 * C C
 * C B
 * J B
 * B C
 * J J
 * --------------
 * Sample Output:
 * 5 3 2
 * 2 3 5
 * B B
 */
#include <stdio.h>

char getCh(int N)
{
	char ch;

	switch (N) {
	case 0: ch = 'B'; break;
	case 1: ch = 'C'; break;
	case 2: ch = 'J'; break;
	}
	return ch;
}

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i, Awin = 0, Bwin = 0, draw = 0;
	char A, B, chA, chB;
	int a[3] = {0}, b[3] = {0};		// B,C,J
	int acount = 0, bcount = 0;

	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c %c\n", &A, &B);
		switch (A) {
		case 'B':
			if (B == 'B')
				draw++;
			else if (B == 'C') {
				Awin++;
				a[0]++;
			} else {
				Bwin++;
				b[2]++;
			}
			break;
		case 'C':
			if (B == 'C')
				draw++;
			else if (B == 'J') {
				Awin++;
				a[1]++;
			} else {
				Bwin++;
				b[0]++;
			}
			break;
		case 'J':
			if (B == 'J')
				draw++;
			else if (B == 'B') {
				Awin++;
				a[2]++;
			} else {
				Bwin++;
				b[1]++;
			}
			break;
		}
	}
	for (i = 1; i < 3; i++) {
		if (a[acount] < a[i])
			acount = i;
		if (b[bcount] < b[i])
			bcount = i;
	}
	chA = getCh(acount);
	chB = getCh(bcount);

	printf("%d %d %d\n", Awin, draw, N-Awin-draw);
	printf("%d %d %d\n", Bwin, draw, N-Bwin-draw);
	printf("%c %c\n", chA, chB);

	return 0;
}


