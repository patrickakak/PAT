#include <iostream>
using namespace std;
int main() {
	string s = "0123456789ABC";
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	printf("#%c%c%c%c%c%c", s[r/13], s[r%13], s[g/13], s[g%13], s[b/13], s[b%13]);
	return 0;
}
