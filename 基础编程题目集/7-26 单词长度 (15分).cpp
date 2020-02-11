#include <iostream>
using namespace std;
int main() {
	char ch;
	int len = 0, flag = 0;
	while (scanf("%c", &ch) && ch != '.') {
		if (ch != ' ') len++;
		else {
			if (len == 0) continue;
			if (flag == 0) {
				printf("%d", len);
				flag = 1;
			} else printf(" %d", len);
			len = 0;
		}
	}
	if (len == 0) return 0;
	if (flag == 0) {
		printf("%d", len);
		flag = 1;
	} else printf(" %d", len);
	return 0;
}
