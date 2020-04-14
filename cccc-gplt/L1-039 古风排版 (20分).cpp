#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k = 0, flag = 0;
	string s;
	scanf("%d\n", &n);
	getline(cin, s);
	int col = s.length()/n + (s.length()%n == 0 ? 0 : 1);
	vector<vector<int>> m(n, vector<int>(col, ' '));
	for (int i = col-1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			m[j][i] = s[k++];
			if (k == s.length()) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < col; j++)
			printf("%c", m[i][j]);
		printf("\n");
	}
	return 0;
}
