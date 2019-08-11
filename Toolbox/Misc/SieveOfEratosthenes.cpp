/**
 * To select primes,
 * the sieve of Eratosthenes algorithm
 *    T = O(NloglogN)
 */
#include <cstdio>

const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};

void Find_Prime()
{
	for (int i = 2; i < maxn; i++)
		if (p[i] == false) {
			prime[num++] = i;
			for (int j = i+i; j < maxn; j += i)
				p[j] = true;
		}
}

int main()
{
	Find_Prime();

	for (int i = 0; i < num; i++)
		printf("%d ", prime[i]);

	return 0;
}

