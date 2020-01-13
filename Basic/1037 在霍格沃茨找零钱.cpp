#include <iostream>
using namespace std;
int main() {
	int a, b, c, t, u, v, x, y, z;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &t, &u, &v);
	if (a > t || (a == t && b > u) || (a == t && b == u && c > v)) {
		swap(a, t); swap(b, u); swap(c, v);
		cout << '-';
	}
	z = v < c ? v - c + 29 : v - c;
	u = v < c ? u - 1 : u;
	y = u < b ? u - b + 17 : u - b;
	x = u < b ? t - a - 1 : t - a;
	cout << x << '.' << y << '.' << z;
	return 0;
}
