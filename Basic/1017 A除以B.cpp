/**
 * Sample input:
 * 123456789050987654321 7
 * -----------------------
 * Sample output:
 * 17636684150141093474 3
 */
#include <cstdio>
#include <cstring>

#define maxn 1010
struct bigNum {
	int d[maxn];
	int len;
	bigNum() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bigNum change(char str[])
{
	bigNum a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len-i-1] - '0';
	return a;
}

bigNum divide(bigNum a, int b, int& r)
{
	bigNum c;
	c.len = a.len;
	for (int i = a.len-1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		if (r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;
			r = r % b;
		}
	}
	while (c.len-1 >= 1 && c.d[c.len-1] == 0)
		c.len--;
	return c;
}

void print(bigNum a)
{
	for (int i = a.len-1; i >= 0; i--)
		printf("%d", a.d[i]);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	char str[maxn];
	int b, r = 0;

	scanf("%s%d", str, &b);
	bigNum a = change(str);
	print(divide(a, b, r));
	printf(" %d", r);

	return 0;
}


