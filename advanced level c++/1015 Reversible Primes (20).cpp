#include <iostream>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int n, d;
	while (scanf("%d", &n) != EOF) {
		if (n < 0) break;
		scanf("%d", &d);
		if (!isprime(n)) {
			printf("No\n");
			continue;
		}
		int len = 0, arr[100];
		do {
			arr[len++] = n % d;
			n = n / d;
		} while (n != 0);
		for (int i = 0; i < len; i++)
			n = n * d + arr[i];
		printf("%s\n", isprime(n) ? "Yes" : "No");
	}
	return 0;
}
