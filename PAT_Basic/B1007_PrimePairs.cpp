/**
 * Sample input:
 * 20
 * ------------
 * Sample output:
 * 4
 */
#include <cstdio>
#include <cmath>

#define maxn 100010
int prime[maxn], pNum = 0;

bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0) return false;
	return true;
}

void findPrime()
{
	for (int i = 1; i < maxn; i++)
		if (isPrime(i))
			prime[pNum++] = i;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, cnt = 0;

	scanf("%d", &n);
	findPrime();
	for (int i = 1; prime[i] <= n; i++)
		if (prime[i] - prime[i-1] == 2)
			cnt++;
	printf("%d\n", cnt);

	return 0;
}


