#include <iostream>
using namespace std;
long long a, b, c, d;
long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}
void fun(long long m, long long n) {
	if (m * n == 0) {
		cout << (n == 0 ? "Inf" : "0");
		return ;
	}
	bool flag = (m < 0 && n > 0) || (m > 0 && n < 0);
	m = abs(m); n = abs(n);
	long long q = m / n;
	cout << (flag ? "(-" : "");
	if (q != 0) cout << q;
	if (m % n == 0) {
		if (flag) cout <<')';
		return ;
	}
	if (q != 0) cout << ' ';
	m -= q * n;
	long long t = gcd(m, n);
	m /= t; n /= t;
	cout << m << '/' << n << (flag ? ")" : "");
}
int main() {
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	fun(a, b); cout << " + "; fun(c, d); cout << " = "; fun(a*d + b*c, b*d); cout << endl;
	fun(a, b); cout << " - "; fun(c, d); cout << " = "; fun(a*d - b*c, b*d); cout << endl;
	fun(a, b); cout << " * "; fun(c, d); cout << " = "; fun(a*c, b*d); cout << endl;
	fun(a, b); cout << " / "; fun(c, d); cout << " = "; fun(a*d, b*c);
	return 0;
}
