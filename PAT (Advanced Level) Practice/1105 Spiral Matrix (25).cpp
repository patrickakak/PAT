#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int mat[10010][10010];
int main() {
	int k, m, n, index = 0;
	cin >> k;
	for (n = sqrt(k); n >= 1; n--)
		if (k % n == 0) {
			m = k / n;
			break;
		}
	vector<int> v(k);
	for (int i = 0; i < k; i++) scanf("%d", &v[i]);
	sort(v.rbegin(), v.rend());
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= n-i+1 && index < k; j++)
			mat[i][j] = v[index++];
		for (int j = i+1; j <= m-i+1 && index < k; j++)
			mat[j][n-i+1] = v[index++];
		for (int j = n-i; j >= i && index < k; j--)
			mat[m-i+1][j] = v[index++];
		for (int j = m-i; j >= i+1 && index < k; j--)
			mat[j][i] = v[index++];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != 1) printf(" ");
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
