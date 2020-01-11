/**
 * Sample input:
 * 15 43 71
 * ------------
 * Sample output:
 * #123456
 */
#include <stdio.h>

char arr[3] = {'A', 'B', 'C'};

int main()
{
	// freopen("test.txt", "r", stdin);
	int R, G, B;
	int r1, r2, g1, g2, b1, b2;

	scanf("%d %d %d", &R, &G, &B);
	r1 = R / 13; r2 = R % 13;
	printf("#%c%c", r1 <= 9 ? r1+'0' : arr[r1-10],
			r2 <= 9 ? r2+'0' : arr[r2-10]);
	g1 = G / 13; g2 = G % 13;
	printf("%c%c", g1 <= 9 ? g1+'0' : arr[g1-10],
			g2 <= 9 ? g2+'0' : arr[g2-10]);
	b1 = B / 13; b2 = B % 13;
	printf("%c%c\n", b1 <= 9 ? b1+'0' : arr[b1-10],
			b2 <= 9 ? b2+'0' : arr[b2-10]);

	return 0;
}

