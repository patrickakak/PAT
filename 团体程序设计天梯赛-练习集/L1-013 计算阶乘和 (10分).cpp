#include <iostream>
using namespace std;
int main() {
	int n, tmp = 1, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		tmp *= i;
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}
