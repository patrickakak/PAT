#include <iostream>
using namespace std;
int main() {
	int a, b, n, acnt = 0, bcnt = 0;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		int j1, j2, y1, y2;
		scanf("%d%d%d%d", &j1, &j2, &y1, &y2);
		if (j2 == y2) continue;
		if (j2 == j1+y1) acnt++;
		if (y2 == j1+y1) bcnt++;
		if (acnt > a || bcnt > b) {
			printf("%c\n%d\n", acnt > a ? 'A':'B', acnt > a ? bcnt : acnt);
			return 0;
		}
	}
	return 0;
}
