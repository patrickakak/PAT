#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long double sum = 0, tmp;
	for (int i = 0; i < n; i++) {
		scanf("%Lf", &tmp);
		sum += tmp * (i+1) * (n - i);
	}
	printf("%.2Lf", sum);
	return 0;
}
