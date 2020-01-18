#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n, cnt = 0;
	char a[100], b[100];
	double tmp, sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		sscanf(a, "%lf", &tmp);
		sprintf(b, "%.2f", tmp);
		int flag = 0;
		for (int j = 0; j < strlen(a); j++)
			if (a[j] != b[j]) {
				flag = 1;
				break;
			}
		if (flag || tmp < -1000 || tmp > 1000) {
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		} else {
			sum += tmp;
			cnt++;
		}
	}
	if (cnt != 0)
		printf("The average of %d number%s is %.2f", cnt, cnt > 1 ? "s" : "", sum / cnt);
	else
		printf("The average of 0 numbers is Undefined");
	return 0;
}
