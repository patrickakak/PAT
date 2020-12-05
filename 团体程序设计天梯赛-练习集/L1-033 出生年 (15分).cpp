#include <iostream>
using namespace std;
int main() {
	int yyyy, n, hashTbl[10] = {0}, d[4] = {0};
	cin >> yyyy >> n;
	for (int i = yyyy; i <= 9999; i++) {
		fill(hashTbl, hashTbl+10, 0);
		d[0] = i/1000;
		d[1] = i/100%10;
		d[2] = i%100/10;
		d[3] = i%100%10;
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int t = d[j];
			if (hashTbl[t] == 0) {
				hashTbl[t]++;
				cnt++;
			}
		}
		if (cnt == n) {
			printf("%d %04d", i-yyyy, i);
			break;
		}
	}
	return 0;
}
