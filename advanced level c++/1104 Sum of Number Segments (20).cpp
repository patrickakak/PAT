#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	double sum = 0, tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &tmp);
		sum += tmp * i * (n - i + 1);
	}
	printf("%.2f", sum);
	return 0;
}
