#include <iostream>
using namespace std;
int a[2010], b[2010], pro[2010], sum[2010];
int main() {
	int n1, n2, c, e, flag = 1;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		scanf("%d%d", &c, &e);
		a[e] = c;
	}
	cin >> n2;
	for (int i=0; i<n2; i++) {
		scanf("%d%d", &c, &e);
		b[e] = c;
	}
	for (int i = 0; i < 2010; i++) {
		sum[i] += a[i] + b[i];
		for (int j = 0; j < 2010; j++)
			if (a[i] != 0 && b[j] != 0)
				pro[i+j] += a[i] * b[j];
	}
	for (int i = 2009; i >= 0; i--)
		if (pro[i] != 0) {
			if (flag == 1) flag = 0;
			else printf(" ");
			printf("%d %d", pro[i], i);
		}
	if (flag == 1) printf("0 0");
	printf("\n");
	flag = 1;
	for (int i = 2009; i >= 0; i--)
		if (sum[i]!=0) {
			if (flag == 1) flag = 0;
			else printf(" ");
			printf("%d %d", sum[i], i);
		}
	if (flag == 1) printf("0 0");
	return 0;
}
