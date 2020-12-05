#include <iostream>
using namespace std;
char a[110][110], b[110][110];
int main() {
	char c;
	int n, flag = 0;
	cin >> c >> n;
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++) scanf("%c", &a[i][j]);
	}
	for (int i = n; i >= 1; i--)
		for (int j = n; j >= 1; j--)
			b[n-i+1][n-j+1] = a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] != b[i][j]) flag = 1;
	if (flag == 0) printf("bu yong dao le\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (b[i][j] == '@') printf("%c", c);
			else printf(" ");
		printf("\n");
	}
	return 0;
}
