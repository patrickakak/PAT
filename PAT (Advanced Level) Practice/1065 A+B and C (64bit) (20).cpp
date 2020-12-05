#include <iostream>
using namespace std;
int main() {
	long long t, a, b, c, sum;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int flag = 0;
		scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) flag = 1;
		else if (a < 0 && b < 0 && sum >= 0) flag = 0;
		else flag = sum > c ? 1 : 0;
		printf("Case #%d: %s\n", i, flag == 1 ? "true" : "false");
	}
	return 0;
}
