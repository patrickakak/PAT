#include <iostream>
using namespace std;
int main() {
	int n, row = 1, cnt = 1;
	char c;
	cin >> n >> c;
	while (cnt + 2 * (2 * row + 1) <= n) {
		cnt += 2 * (2 * row + 1);
		row++;
	}
	row -= 1;
	for (int i = row; i >= 1; i--) {
		for (int j = 0; j < row - i; j++) printf(" ");
		for (int j = 0; j < i * 2 + 1; j++) printf("%c", c);
		printf("\n");
	}
	for (int i = 0; i < row; i++) printf(" ");
	printf("%c\n", c);
	for (int i = 1; i <= row; i++) {
		for (int j = 0; j < row - i; j++) printf(" ");
		for (int j = 0; j < i * 2 + 1; j++) printf("%c", c);
		printf("\n");
	}
	printf("%d", n - cnt);
	return 0;
}
