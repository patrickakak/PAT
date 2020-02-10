#include <iostream>
using namespace std;
int main() {
	double a, d;
	int b;
	char c;
	scanf("%lf %d %c %lf", &a, &b, &c, &d);
	printf("%c %d %.2f %.2f", c, b, a, d);
	return 0;
}
