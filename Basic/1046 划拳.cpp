/**
 * Sample Input:
 * 5
 * 8 10 9 12
 * 5 10 5 10
 * 3 8 5 12
 * 12 18 1 13
 * 4 16 12 15
 * ------------
 * Sample Output:
 * 1 2
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i, tot;
	int Acount, Bcount;
	int a1, a2, b1, b2;

	Acount = Bcount = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		tot = a1 + b1;
		if (a2 != b2) {
			if (tot == a2)
				Bcount++;
			else if (tot == b2)
				Acount++;
		}
	}
	printf("%d %d\n", Acount, Bcount);

	return 0;
}

