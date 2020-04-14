#include <iostream>
using namespace std;
int main() {
	int h, m;
	scanf("%d:%d", &h, &m);
	if (h < 12) {
		printf("Only %02d:%02d.  Too early to Dang.", h, m);
		return 0;
	}
	if (h == 12 && m == 0) {
		printf("Only %02d:%02d.  Too early to Dang.", h, m);
		return 0;
	}
	int cnt = h - 12;
	if (m > 0) cnt++;
	for (int i = 0; i < cnt; i++) printf("Dang");
	return 0;
}
