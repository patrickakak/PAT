#include <cstdio>
int main() {
	int a, b, sum=0;
	scanf("%d%d", &a, &b);
	for (int i = a, j = 1; i <= b; i++, j++) {
		printf("%5d", i);
		sum += i;
		if (j % 5 == 0) printf("\n");
	}
	j--;
	if (j % 5 != 0) printf("\n");
	printf("Sum = %d", sum);
	return 0;
}
