#include <iostream>
using namespace std;
int main() {
	int k, a[54], b[54], seq[54];
	cin >> k;
	for (int i = 0; i < 54; i++) a[i] = i;
	for (int i = 0; i < 54; i++) scanf("%d", &seq[i]);
	while (k--) {
		for (int i = 0; i < 54; i++) b[seq[i]-1] = a[i];
		for (int i = 0; i < 54; i++) a[i] = b[i];
	}
	string s = "SHCDJ";
	for (int i = 0; i < 54; i++) {
		if (i != 0) printf(" ");
		printf("%c%d", s[a[i]/13], a[i]%13+1);
	}
	return 0;
}
