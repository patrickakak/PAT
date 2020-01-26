#include <iostream>
using namespace std;
int sz, n, h[10100];
bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
void insert(int key) {
	for (int step = 0; step < sz; step++) {
		int index = (key + step * step) % sz;
		if (h[index] == 0) {
			h[index] = 1;
			cout << index % sz;
			return ;
		}
	}
	cout << '-';
}
int main() {
	cin >> sz >> n;
	while (!isprime(sz)) sz++;
	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		if (i != 0) cout << ' ';
		insert(key);
	}
	return 0;
}
