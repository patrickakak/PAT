#include <iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if (n == 5) printf("7");
	else {
		n = (n+2) % 7;
		printf("%d",n);
	}
	return 0;
}
