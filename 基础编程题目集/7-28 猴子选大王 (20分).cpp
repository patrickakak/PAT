#include <iostream>
using namespace std;
bool hit[1005];
int main() {
	int n;
	scanf("%d", &n);
	int left = n, cnt = 0, flag = 0;
	while (1) {
		for (int i = 1; i <= n; i++) {
			if (hit[i] == true) continue;
			if (++cnt == 3) {
				left--;
				cnt = 0;
				hit[i] = true;
			}
			if (left == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	for (int i = 1; i <= n; i++)
		if (hit[i] == false) {
			printf("%d", i);
			break;
		}
	return 0;
}
