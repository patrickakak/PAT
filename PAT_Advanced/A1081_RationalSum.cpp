/**
 * Sample input1:
 * 5
 * 2/5 4/15 1/30 -2/60 8/3
 * Sample output1:
 * 3 1/3
 * ------------------
 * Sample input2:
 * 2
 * 4/3 2/3
 * Sample output2:
 * 2
 * ------------------
 * Sample input3:
 * 3
 * 1/3 -1/6 1/8
 * Sample output3:
 * 7/24
 */
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Fraction {
	ll up, down;
};

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

void show(Fraction r)
{
	reduction(r);
	if (r.down == 1) printf("%lld\n", r.up);
	else if (abs(r.up) > r.down)
		printf("%lld %lld/%lld\n", r.up/r.down, abs(r.up)%r.down, r.down);
	else
		printf("%lld/%lld\n", r.up, r.down);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	Fraction sum, tmp;
	sum.up = 0; sum.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &tmp.up, &tmp.down);
		sum = add(sum, tmp);
	}
	show(sum);

	return 0;
}


