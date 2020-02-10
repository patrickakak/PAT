#include <iostream>
using namespace std;
int main() {
	int t, turtle = 0, hare = 0, timer = 0, rest = 0;
	scanf("%d", &t);
	while (t--) {
		if (timer == 10 && rest <= 0) {
			if (hare > turtle) rest = 30;
			timer = 0;
		}
		turtle += 3;
		if (rest <= 0) {
			hare += 9;
			timer++;
		} else rest--;
	}
	if (turtle > hare) printf("@_@ %d", turtle);
	else if (turtle < hare) printf("^_^ %d", hare);
	else printf("-_- %d", turtle);
	return 0;
}
