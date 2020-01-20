#include <iostream>
using namespace std;
long long a, b, c, d;
long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}
void f(long long n, long long d) {
	if (n * d == 0) {
		cout << (d == 0 ? "Inf" : "0");
		return ;
	}
	bool flag = (n < 0 && d > 0) || (n > 0 && d < 0);
	n = abs(n); d = abs(d);
	long long q = n / d;
	cout << (flag ? "(-" : "");
	if (q != 0) cout << q;
	if (n % d == 0) {
		if (flag) cout <<')';
		return ;
	}
	if (q != 0) cout << ' ';
	n -= q * d;
	long long t = gcd(n, d);
	n /= t; d /= t;
	cout << n << '/' << d << (flag ? ")" : "");
}
int main() {
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	f(a, b); cout << " + "; f(c, d); cout << " = "; f(a*d + b*c, b*d); cout << endl;
	f(a, b); cout << " - "; f(c, d); cout << " = "; f(a*d - b*c, b*d); cout << endl;
	f(a, b); cout << " * "; f(c, d); cout << " = "; f(a*c, b*d); cout << endl;
	f(a, b); cout << " / "; f(c, d); cout << " = "; f(a*d, b*c);
	return 0;
}
