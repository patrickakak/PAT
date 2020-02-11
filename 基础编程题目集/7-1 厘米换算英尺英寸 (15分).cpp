#include <iostream>
using namespace std;
int main() {
	double cm;
	scanf("%lf", &cm);
	int foot = (int)cm / 30.48;
	double inch = (cm / 30.48 - foot) * 12;
	printf("%d %d\n", foot, (int)inch);
	return 0;
}
