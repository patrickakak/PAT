#include <iostream>
using namespace std;
int main() {
	int year, hour;
	scanf("%d%d", &year, &hour);
	int h1, h2;
	if (hour <= 40) {
		h1 = hour;
		h2 = 0;
	} else {
		h1 = 40;
		h2 = hour - 40;
	}
	if (year < 5) printf("%.2f", 30.0 * h1 + 30.0 * 1.5 * h2);
	else printf("%.2f", 50.0 * h1 + 50.0 * 1.5 * h2);
	return 0;
}
