#include <iostream>
using namespace std;
int main() {
	int n, u, d;
	scanf("%d%d%d", &n, &u, &d);
	int min = 0;
	int flag = 0;
	int ht = 0;
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
