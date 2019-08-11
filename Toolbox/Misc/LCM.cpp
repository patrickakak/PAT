/**
 * Least Common Multiple
 */
#include <cstdio>

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	int m, n, lcm;

	scanf("%d%d", &m, &n);
	lcm = m / gcd(m, n) * n;
	printf("%d\n", lcm);

	return 0;
}

