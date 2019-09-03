/**
 * Sample input:
 * 4 4
 * 10 6 4 15
 * -------------
 * Sample output:
 * 0 1 4 -
 */
#include <cstdio>
#include <cmath>

#define maxn 11111

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
		if (n % i == 0) return false;
	return true;
}
bool hashTbl[maxn] = {0};

int main()
{
	// freopen("tst.txt", "r", stdin);
	int m, n, a;

	scanf("%d%d", &m, &n);
	while (!isPrime(m))
		m++;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		int M = a % m;
		if (hashTbl[M] == false) {
			hashTbl[M] = true;
			if (i == 0) printf("%d", M);
			else printf(" %d", M);
		} else {
			int step;
			for (step = 1; step < m; step++) {
				M = (a + step * step) % m;
				if (hashTbl[M] == false) {
					hashTbl[M] = true;
					if (i == 0) printf("%d", M);
					else printf(" %d", M);
					break;
				}
			}
			if (step >= m) {
				if (i > 0) printf(" ");
				printf("-");
			}
		}
	}

	return 0;
}


