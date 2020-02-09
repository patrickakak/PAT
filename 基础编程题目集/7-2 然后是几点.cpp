#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int hh = a / 100, mm = a % 100;
	int mins = hh * 60 + mm;
	int c = mins + b;
	printf("%d%02d", c/60, c%60);
	return 0;
}
