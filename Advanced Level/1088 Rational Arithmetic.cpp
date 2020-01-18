/**
 * Sample input1:
 * 2/3 -4/2
 * Sample output1:
 * 2/3 + (-2) = (-1 1/3)
 * 2/3 - (-2) = 2 2/3
 * 2/3 * (-2) = (-1 1/3)
 * 2/3 / (-2) = (-1/3)
 * ---------------------
 * Sample input2:
 * 5/3 0/6
 * Sample output2:
 * 1 2/3 + 0 = 1 2/3
 * 1 2/3 - 0 = 1 2/3
 * 1 2/3 * 0 = 0
 * 1 2/3 / 0 = Inf
 */
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Fraction {
	ll up, down;
} a, b;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

Fraction reduction(Fraction ret)
{
	if (ret.down < 0) {
		ret.up = -ret.up;
		ret.down = -ret.down;
	}
	if (ret.up == 0)
		ret.down = 1;
	else {
		int d = gcd(abs(ret.up), abs(ret.down));
		ret.up /= d;
		ret.down /= d;
	}
	return ret;
}

Fraction add(Fraction f1, Fraction f2)
{
	Fraction ret;
	ret.up = f1.up * f2.down + f2.up * f1.down;
	ret.down = f1.down * f2.down;
	return reduction(ret);
}

Fraction minu(Fraction f1, Fraction f2)
{
	Fraction ret;
	ret.up = f1.up * f2.down - f2.up * f1.down;
	ret.down = f1.down * f2.down;
	return reduction(ret);
}

Fraction multi(Fraction f1, Fraction f2)
{
	Fraction ret;
	ret.up = f1.up * f2.up;
	ret.down = f1.down * f2.down;
	return reduction(ret);
}

Fraction divide(Fraction f1, Fraction f2)
{
	Fraction ret;
	ret.up = f1.up * f2.down;
	ret.down = f1.down * f2.up;
	return reduction(ret);
}

void show(Fraction r)
{
	r = reduction(r);
	if (r.up < 0) printf("(");
	if (r.down == 1) printf("%lld", r.up);
	else if (abs(r.up) > r.down)
		printf("%lld %lld/%lld", r.up/r.down, abs(r.up)%r.down, r.down);
	else
		printf("%lld/%lld", r.up, r.down);
	if (r.up < 0) printf(")");
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	show(a);
	printf(" + ");
	show(b);
	printf(" = ");
	show(add(a, b));
	printf("\n");
	show(a);
	printf(" - ");
	show(b);
	printf(" = ");
	show(minu(a, b));
	printf("\n");
	show(a);
	printf(" * ");
	show(b);
	printf(" = ");
	show(multi(a, b));
	printf("\n");
	show(a);
	printf(" / ");
	show(b);
	printf(" = ");
	if (b.up == 0) printf("Inf");
	else show(divide(a, b));

	return 0;
}


