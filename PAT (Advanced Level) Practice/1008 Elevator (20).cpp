#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0, pre = 0, tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp - pre > 0) sum += 6 * (tmp - pre);
		else sum += 4 * (pre - tmp);
		sum += 5;
		pre = tmp;
	}
	printf("%d", sum);
	return 0;
}
