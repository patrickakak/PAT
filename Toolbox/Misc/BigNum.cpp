/**
 * Big number calculation (integer w/ more than 1000 digits)
 */
#include <cstdio>

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

int compare(bigNum a, bigNum b)
{
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len-1; i >= 0; i--)
			if (a.d[i] > b.d[i]) return 1;
			else if (a.d[i] < b.d[i]) return -1;
		return 0;
	}
}

bigNum add(bigNum a, bigNum b)
{
	bigNum c;
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

// Caution: a > b
bigNum sub(bigNum a, bigNum b)
{
	bigNum c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len-1 >= 1 && c.d[c.len-1] == 0)
		c.len--;
	return c;
}

bigNum multi(bigNum a, int b)
{
	bigNum c;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int tmp = a.d[i] * b + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

// r: remainder (should be 0 when invoking divide())
// c: quotient
bigNum divide(bigNum a, int b, int &r)
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
	int num;

	scanf("%s", str);
	scanf("%d", &num);
	bigNum a = change(str);
	bigNum b = multi(a, num);
	print(b);

	return 0;
}


