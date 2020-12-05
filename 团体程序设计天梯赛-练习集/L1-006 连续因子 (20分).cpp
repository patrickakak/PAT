#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int maxlen = 0, fir = -1, sqr = sqrt(n);
	for (int i = 2; i <= sqr+1; i++) {
		int fac = i, len = 0, j = i;
		while (n%fac == 0) {
			len++;
			fac *= ++j;
		}
		if (len > maxlen) {
			maxlen = len;
			fir = i;
		}
	}
	if (fir == -1) {
		printf("1\n%d", n);
		return 0;
	}
	printf("%d\n", maxlen);
	for (int i = 0; i < maxlen; i++) {
		if (i != 0) printf("*");
		printf("%d", fir+i);
	}
	return 0;
}
