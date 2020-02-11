#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int x = 1; 2*x*x <= n; x++)
		for (int y = x; x*x + y*y <= n; y++)
			if (x*x + y*y == n) {
				printf("%d %d\n", x, y);
				cnt++;
			}
	if (cnt == 0) printf("No Solution");
	return 0;
}
