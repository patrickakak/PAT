#include <iostream>
using namespace std;
bool ispalindromic(int a[], int len) {
	for (int i=0, j=len-1; i<j; i++, j--)
		if (a[i] != a[j]) return false;
	return true;
}
int main() {
	int n, b, a[100], len = 0;
	cin >> n >> b;
	do {
		a[len++] = n % b;
		n /= b;
	} while (n);
	if (ispalindromic(a, len)) printf("Yes\n");
	else printf("No\n");
	for (int i = len - 1; i >= 0; i--) {
		if (i != len - 1) printf(" ");
		printf("%d", a[i]);
	}
	return 0;
}
