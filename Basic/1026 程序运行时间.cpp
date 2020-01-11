#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int c1, c2;
	const int clk_tck = 100;
	cin >> c1 >> c2;
	int sec = round(1.0 * (c2 - c1) / clk_tck);
	int hh = sec / 3600;
	sec %= 3600;
	int mm = sec / 60, ss = sec % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}
