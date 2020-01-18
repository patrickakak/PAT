#include <iostream>
using namespace std;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main() {
	int a, b, c, d, k, i = 1;
	scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &k);
	if (1.0 * a / b > 1.0 * c / d) {
		swap(a, c); swap(b, d);
	}
	for (; ; i++)
		if (1.0 * i / k > 1.0 * a / b) break;
	bool flag = true;
	for (int j = i; ; j++)
		if (1.0 * j / k < 1.0 * c / d) {
			int d = gcd(j, k);
			if (d != 1) continue;
			if (flag == true) flag = false;
			else cout << ' ';
			printf("%d/%d", j/d, k/d);
		} else break;
	return 0;
}
