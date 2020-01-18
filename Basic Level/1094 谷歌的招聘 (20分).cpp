#include <iostream>
using namespace std;
bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int l, k;
	string s;
	cin >> l >> k >> s;
	for (int i = 0; i + k <= l; i++) {
		string t = s.substr(i, k);
		if (isPrime(stoi(t))) {
			cout << t;
			return 0;
		}
	}
	cout << "404\n";
	return 0;
}
