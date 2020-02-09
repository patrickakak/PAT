#include <cstdio>
int main() {
	int sp;
	scanf("%d", &sp);
	if (sp <= 60) printf("Speed: %d - OK\n", sp);
	else printf("Speed: %d - Speeding\n", sp);
	return 0;
}
