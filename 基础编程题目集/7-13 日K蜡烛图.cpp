#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	double open, close, high, low;
	scanf("%lf%lf%lf%lf", &open, &high, &low, &close);
	if (high < low) swap(high, low);
	int flag = 0;
	if (close < open) printf("BW-Solid");
	else if (close > open) printf("R-Hollow");
	else printf("R-Cross");
	if (low < open && low < close) {
		printf(" with Lower Shadow");
		flag = 1;
	}
	if (high > open && high > close) {
		if (flag == 1) printf(" and ");
		else printf(" with ");
		printf("Upper Shadow");
	}
	return 0;
}
