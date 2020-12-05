#include <iostream>
using namespace std;
int main() {
	int n, left, right, a = 1, now = 1, cnt = 0;
	scanf("%d", &n);
	while (n / a) {
		left = n / (a * 10), now = n / a % 10, right = n % a;
		if (now == 0) cnt += left * a;
		else if (now == 1) cnt += left * a + right + 1;
		else cnt += (left + 1) * a;
		a *= 10;
	}
	printf("%d", cnt);
	return 0;
}
