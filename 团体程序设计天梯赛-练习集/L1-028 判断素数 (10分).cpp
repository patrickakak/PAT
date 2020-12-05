#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	int sqr = sqrt(n);
	for (int i = 2; i <= sqr; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		printf("%s\n", isprime(tmp) ? "Yes" : "No");
	}
	return 0;
}
