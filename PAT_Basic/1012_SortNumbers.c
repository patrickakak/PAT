/**
 * Sample Input1:
 * 13 1 2 3 4 5 6 7 8 9 10 20 16 18
 * Sample Output1:
 * 30 11 2 9.7 9
 * --------------------
 * Sample Input2:
 * 8 1 2 4 5 6 7 9 16
 * Sample Output2:
 * N 11 2 N 9
 */
#include <stdio.h>

int main()
{
	// freopen("test.txt", "r", stdin);
	int N, i, A1=0, A2=0, A3=0, A4=0, A5=0;
	int tmp, flag=1, flag2=0, cnt=0, arrow;

	scanf("%d", &N);
	for (i=0; i<N; i++) {
		scanf("%d", &tmp);
		arrow = tmp%5;
		switch (arrow) {
		case 0:
			if (tmp%2 == 0)
				A1 += tmp;
			break;
		case 1:
			flag2 = 1;
			if (flag == 1) {
				A2 += tmp;
				flag = 0;
			} else {
				A2 -= tmp;
				flag = 1;
			}
			break;
		case 2:
			A3++;
			break;
		case 3:
			A4 += tmp;
			cnt++;
			break;
		case 4:
			if (A5 < tmp)
				A5 = tmp;
			break;
		}
	}

	if (A1 == 0) printf("N "); else printf("%d ", A1);
	if (A2 == 0 && flag2 == 0) printf("N "); else printf("%d ", A2);
	if (A3 == 0) printf("N "); else printf("%d ", A3);
	if (A4 == 0) printf("N "); else printf("%.1lf ", (double)A4/cnt);
	if (A5 == 0) printf("N"); else printf("%d", A5);

	return 0;
}

