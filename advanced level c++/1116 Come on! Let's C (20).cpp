#include <iostream>
#include <unordered_map>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}
int main() {
	int n, k, id;
	cin >> n;
	unordered_map<int, int> exist, checked;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &id);
		exist[id] = i;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d", &id);
		if (exist[id]) {
			if (checked[id]) {
				printf("%04d: Checked\n", id);
				continue;
			} else {
				if (exist[id] == 1) printf("%04d: Mystery Award\n", id);
				else if (isprime(exist[id])) printf("%04d: Minion\n", id);
				else printf("%04d: Chocolate\n", id);
				checked[id] = 1;
			}
		} else printf("%04d: Are you kidding?\n", id);
	}
	return 0;
}
