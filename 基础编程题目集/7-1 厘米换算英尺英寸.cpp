#include <iostream>
using namespace std;
int main() {
	double centimeters, inches;
	int foot;
	scanf("%lf", &centimeters);
	foot = (int)centimeters / 30.48;
	inches = (centimeters/30.48 - foot)*12;
	printf("%d %d\n", foot, (int)inches);
	return 0;
}
