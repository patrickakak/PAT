#include <iostream>
using namespace std;
struct Fraction {
	int up, down;
};
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
Fraction reduce(Fraction f) {
	int d = gcd(f.up, f.down);
	f.up /= d;
	f.down /= d;
	return f;
}
Fraction add(Fraction a, Fraction b) {
	Fraction f;
	f.up = a.up * b.down + b.up * a.down;
	f.down = a.down * b.down;
	return reduce(f);
}
int main() {
	Fraction a, b;
	scanf("%d/%d %d/%d", &a.up, &a.down, &b.up, &b.down);
	Fraction f = add(a, b);
	if (f.down == 1) printf("%d", f.up);
	else printf("%d/%d", f.up, f.down);
	return 0;
}
