/**
 * Binary Indexed Tree (aka Fenwick tree)
 *
 * (the most classic use of BIT is to calculate # of elements 
 * less than the current element)
 */
#include <cstdio>
#include <cstring>

const int maxn = 100010;
#define lowbit(i) ((i)&(-i))
int c[maxn];

void update(int x, int v)
{
	for (int i = x; i < maxn; i += lowbit(i))
		c[i] += v;
}

int getSum(int x)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		sum += c[i];
	return sum;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, x;

	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(x, 1);
		printf("%d\n", getSum(x-1));
	}

	return 0;
}


