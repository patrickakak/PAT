#include <iostream>
using namespace std;
int main() {
	int n, u, d, min = 0, flag = 0, ht = 0;
	scanf("%d%d%d", &n, &u, &d);
	while (ht < n) {
		if (flag == 0) {
			ht += u;
			flag = 1;
		} else {
			ht -= d;
			flag = 0;
		}
		min++;
	}
	printf("%d", min);
	return 0;
}
