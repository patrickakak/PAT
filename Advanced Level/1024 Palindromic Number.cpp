/**
 * Sample input1:
 * 67 3
 * Sample output1:
 * 484
 * 2
 * --------------
 * Sample input2:
 * 69 3
 * Sample output2:
 * 1353
 * 3
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1010
struct bigN {
	int d[maxn], len;
	bigN() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bigN change(char str[])
{
	bigN a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len-i-1] - '0';
	return a;
}

bigN add(bigN a, bigN b)
{
	bigN c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry != 0)
		c.d[c.len++] = carry;
	return c;
}

bool Judge(bigN a)
{
	for (int i=0, j=a.len-1; i < j; i++, j--)
		if (a.d[i] != a.d[j])
			return false;
	return true;
}

void print(bigN a)
{
	for (int i = a.len-1; i >= 0; i--)
		printf("%d", a.d[i]);
	printf("\n");
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	char str[maxn];
	int T, k = 0;
	scanf("%s %d", str, &T);
	bigN a = change(str);
	while (k < T && Judge(a) == false) {
		bigN b = a;
		reverse(b.d, b.d + b.len);
		a = add(a, b);
		k++;
	}
	print(a);
	printf("%d\n", k);

	return 0;
}


