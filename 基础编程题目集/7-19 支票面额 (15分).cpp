#include <iostream>
using namespace std;
int main() {
	int n, f, y, flag = 0;
	scanf("%d", &n);
	for (f = 0; f < 100; f++) {
		for (y = 0; y < 100; y++)
			if (100 * f + y - n == 200 * y + 2 * f) {
				flag = 1;
				break;
			}
		if (flag == 1) break;
	}
	if (flag == 1) printf("%d.%d", y, f);
	else printf("No Solution");
	return 0;
}
