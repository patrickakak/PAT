#include <iostream>
using namespace std;
long long gcd(long long a, long long b) { return !b ? abs(a) : gcd(b, a % b); }
int main() {
	long long n, a, b, suma = 0, sumb = 1, d;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &a, &b);
		d = gcd(a, b);
		a = a / d;
		b = b / d;
		suma = a * sumb + suma * b;
		sumb = b * sumb;
		d = gcd(suma, sumb);
		sumb = sumb / d;
		suma = suma / d;
	}
	long long integer = suma / sumb;
	suma = suma - (sumb * integer);
	if (integer != 0) {
		printf("%lld", integer);
		if (suma != 0) printf(" ");
	}
	if (suma != 0) printf("%lld/%lld", suma, sumb);
	if (integer == 0 && suma == 0) printf("0");
	return 0;
}
