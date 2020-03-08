#include <iostream>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	int n, d;
	while (scanf("%d", &n)) {
		if (n < 0) break;
		scanf("%d", &d);
		if (!isprime(n)) {
			printf("No\n");
			continue;
		}
		string s;
		do {
			int r = n%d;
			s += r + '0';
			n /= d;
		} while (n != 0);
		int rev = 0;
		for (int i = 0; i < s.length(); i++)
			rev = rev * d + (s[i] - '0');
		if (isprime(rev)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
