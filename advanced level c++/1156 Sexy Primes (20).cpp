#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	if (isprime(n)) {
		if (isprime(n - 6)) {
			printf("Yes\n%d", n - 6);
			return 0;
		} else if (isprime(n + 6)) {
			printf("Yes\n%d", n + 6);
			return 0;
		}
	}
	while (!(isprime(n) && (isprime(n - 6) || isprime(n + 6)))) n++;
	printf("No\n%d", n);
	return 0;
}
