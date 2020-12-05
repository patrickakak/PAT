#include <iostream>
using namespace std;
int main() {
	int n, tmp, odd = 0, even = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp%2 == 1) odd++;
		else even++;
	}
	printf("%d %d\n", odd, even);
	return 0;
}
