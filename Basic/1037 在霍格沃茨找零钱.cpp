#include <iostream>
using namespace std;
int main() {
	int a, b, c, r, s, t, x, y, z;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &r, &s, &t);
	if (a > r || (a == r && b > s) || (a == r && b == s && c > t)) {
		swap(a, r); swap(b, s); swap(c, t);
		cout << '-';
	}
	z = t < c ? t - c + 29 : t - c;
	s = t < c ? s - 1 : s;
	y = s < b ? s - b + 17 : s - b;
	x = s < b ? r - a - 1 : r - a;
	cout << x << '.' << y << '.' << z;
	return 0;
}
