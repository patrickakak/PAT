#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long double sum = 0, tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%Lf", &tmp);
		sum += tmp * i * (n - i + 1);
	}
	printf("%.2Lf", sum);
	return 0;
}
