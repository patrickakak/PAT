#include <cstdio>
int main() {
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	if (hh > 12) printf("%d:%d PM", hh-12, mm);
	else if (hh == 12) printf("%d:%d PM", hh, mm);
	else printf("%d:%d AM", hh, mm);
	return 0;
}
