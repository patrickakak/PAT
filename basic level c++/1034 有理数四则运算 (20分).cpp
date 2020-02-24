#include <iostream>
using namespace std;
long gcd(long a, long b) {
	return !b ? a : gcd(b, a % b);
}
void f(long n, long d) {
	if (n * d == 0) {
		printf("%s", d == 0 ? "Inf" : "0");
		return ;
	}
	bool flag = (n < 0 && d > 0) || (n > 0 && d < 0);
	n = abs(n), d = abs(d);
	long q = n / d;
	printf("%s", flag ? "(-" : "");
	if (q != 0) printf("%d", q);
	if (n % d == 0) {
		if (flag) printf(")");
		return ;
	}
	if (q != 0) printf(" ");
	n -= q * d;
	long t = gcd(n, d);
	n /= t, d /= t;
	printf("%d/%d%s", n, d, flag ? ")" : "");
}
int main() {
	long a, b, c, d;
	scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
	f(a, b); printf(" + "); f(c, d); printf(" = "); f(a*d + b*c, b*d); printf("\n");
	f(a, b); printf(" - "); f(c, d); printf(" = "); f(a*d - b*c, b*d); printf("\n");
	f(a, b); printf(" * "); f(c, d); printf(" = "); f(a*c, b*d); printf("\n");
	f(a, b); printf(" / "); f(c, d); printf(" = "); f(a*d, b*c);
	return 0;
}
