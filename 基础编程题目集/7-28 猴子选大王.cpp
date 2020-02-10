#include <iostream>
using namespace std;
bool hashTbl[1005] = {false};
int main() {
	int n;
	scanf("%d", &n);
	int left = n, cnt = 0, flag = 0;
	while (1) {
		for (int i = 1; i <= n; i++) {
			if (hashTbl[i] == true) continue;
			cnt++;
			if (cnt == 3) {
				left--;
				cnt = 0;
				hashTbl[i] = true;
			}
			if (left == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	for (int i = 1; i <= n; i++)
		if (hashTbl[i] == false) {
			printf("%d", i);
			break;
		}
	return 0;
}
