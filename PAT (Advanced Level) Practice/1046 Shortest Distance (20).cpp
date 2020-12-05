#include <iostream>
using namespace std;
int d[100010];
int main() {
	int n, tmp;
	cin >> n;
	d[1] = 0;
	for (int i = 2; i < n+2; i++) {
		scanf("%d", &tmp);
		d[i] = d[i-1] + tmp;
	}
	int m, a, b, sum = d[n+1];
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		tmp = abs(d[a]-d[b]);
		printf("%d\n", min(tmp, sum-tmp));
	}
	return 0;
}
