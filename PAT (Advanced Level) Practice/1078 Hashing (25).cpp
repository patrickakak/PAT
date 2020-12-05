#include <iostream>
using namespace std;
int sz, n, h[10100];
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
void insert(int key) {
	for (int step = 0; step <= sz; step++) {
		int idx = (key + step * step) % sz;
		if (h[idx] == 0) {
			h[idx] = 1;
			printf("%d", idx);
			return ;
		}
	}
	printf("-");
}
int main() {
	cin >> sz >> n;
	while (!isprime(sz)) sz++;
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		if (i != 0) printf(" ");
		insert(key);
	}
	return 0;
}
