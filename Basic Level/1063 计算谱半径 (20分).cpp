#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, a, b, max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a * a + b * b > max)
			max = a * a + b * b;
	}
	printf("%.2f", sqrt(1.0*max));
	return 0;
}
