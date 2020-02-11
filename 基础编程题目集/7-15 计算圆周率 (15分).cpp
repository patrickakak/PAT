#include <iostream>
using namespace std;
int main() {
	double eps, sum = 1, up = 1, down = 1;
	scanf("%lf", &eps);
	int i = 1;
	while (up / down > eps) {
		up *= i;
		down *= (2 * i + 1);
		i++;
		sum += up / down;
	}
	printf("%f", 2 * sum);
	return 0;
}
