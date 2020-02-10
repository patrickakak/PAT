#include <iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a = n / 16;
	int c = a * 10 + n % 16;
	printf("%d", c);
	return 0;
}
