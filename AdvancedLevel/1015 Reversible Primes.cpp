/**
 * Sample input:
 * 73 10
 * 23 2
 * 23 10
 * -2
 * -------------
 * Sample output:
 * Yes
 * Yes
 * No
 */
#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	// freopen("tst.txt", "r", stdin);

	int n, D, r[110];

	while (scanf("%d", &n) != EOF) {
		if (n < 0) break;
		scanf("%d", &D);
		if (!isPrime(n))
			printf("No\n");
		else {
			int len = 0;
			do {
				r[len++] = n % D;
				n /= D;
			} while (n != 0);
			for (int i = 0; i < len; i++)
				n = n * D + r[i];
			if (isPrime(n)) printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}


