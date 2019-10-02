/**
 * Sample input:
 * 1234567899
 * --------------
 * Sample output:
 * Yes
 * 2469135798
 */
#include <cstdio>
#include <cstring>

#define maxn 24
struct bigN {
	int len, d[maxn];
	bigN() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

int hashTbl1[10] = {0}, hashTbl2[10] = {0};
bigN change(char *str)
{
	bigN c;
	int len = strlen(str);
	for (int i = len-1; i >= 0; i--) {
		int tmp = str[i] - '0';
		hashTbl1[tmp]++;
		c.d[c.len++] = tmp;
	}
	return c;
}

bigN multi(bigN a, int b)
{
	bigN c;
	int r = 0;
	for (int i = 0; i < a.len; i++) {
		r += a.d[i] * b;
		hashTbl2[r%10]++;
		c.d[c.len++] = r % 10;
		r /= 10;
	}
	while (r != 0) {
		hashTbl2[r%10]++;
		c.d[c.len++] = r % 10;
		r /= 10;
	}
	return c;
}

void print(bigN a)
{
	for (int i = a.len-1; i >= 0; i--)
		printf("%d", a.d[i]);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	char str[maxn];

	scanf("%s", str);
	bigN a = change(str);
	bigN c = multi(a, 2);

	int i;
	for (i = 0; i < 10; i++)
		if (hashTbl1[i] != hashTbl2[i])
			break;
	if (i >= 10) printf("Yes\n");
	else printf("No\n");
	print(c);

	return 0;
}


