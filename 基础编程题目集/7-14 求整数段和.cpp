#include <iostream>
using namespace std;
int main() {
	int a, b, i, cot = 0, sum = 0;
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++) {
		printf("%5d", i);
		cot++;
		if (cot % 5 == 0 && i != b) printf("\n");
	}
	printf("\n");
	for(i = a; i <= b; i++) sum += i;
	printf("Sum = %d", sum);
	return 0;
}
