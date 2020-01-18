#include <iostream>
int main() {
	int n, sum = 0, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		sum += tmp * 10 * (n - 1) + tmp * (n - 1);
	}
	printf("%d", sum);
	return 0;
}
