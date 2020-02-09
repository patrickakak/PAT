#include <math.h>
int IsTheNumber(const int N) {
	int yes = 0, temp, i;
	int arr[10] = {0};
	temp = N;
	while (temp) {
		arr[temp%10]++;
		temp /= 10;
	}
	for (i = 0; i < 10; i++)
		if (arr[i] > 1 && sqrt(N) == (int)sqrt(N)) {
			yes = 1;
			break;
		}
	return yes;
}
