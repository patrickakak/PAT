#include <iostream>
#include <unordered_map>
using namespace std;
bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int n, k, id, rnk;
	cin >> n;
	unordered_map<int, int> m;
	for (int i = 1; i <= n; i++) {
		cin >> id;
		m[id] = i;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> id;
		rnk = m[id];
		if (rnk == 0)
			printf("%04d: Are you kidding?\n", id);
		else if (rnk == -1)
			printf("%04d: Checked\n", id);
		else if (rnk == 1) {
			printf("%04d: Mystery Award\n", id);
			m[id] = -1;
		} else if (isPrime(rnk)) {
			printf("%04d: Minion\n", id);
			m[id] = -1;
		} else {
			printf("%04d: Chocolate\n", id);
			m[id] = -1;
		}
	}
	return 0;
}
