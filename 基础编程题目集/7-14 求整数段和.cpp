#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, sum = 0, cnt = 0;
	cin >> a >> b;
	if (a > b) swap(a, b);
	for (int i = a; i <= b; i++) {
		printf("%5d", i);
		if (++cnt % 5 == 0) printf("\n");
		sum += i;
	}
	if (cnt % 5 != 0) printf("\n");
	printf("Sum = %d", sum);
	return 0;
}
