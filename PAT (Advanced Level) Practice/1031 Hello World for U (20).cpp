#include <iostream>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n1 = 1, n2 = s.length(), cnt = 0;
	for (; n2 >= n1; n2 -= 2, n1 += 1) ;
	n2 += 2, n1 -= 1;
	vector<vector<char>> v(n1, vector<char>(n2, ' '));
	for (int j = 0; j < n1 && cnt < s.length(); j++) v[j][0] = s[cnt++];
	for (int j = 1; j < n2 && cnt < s.length(); j++) v[n1-1][j] = s[cnt++];
	for (int j = n1-2; j >= 0 && cnt < s.length(); j--) v[j][n2-1] = s[cnt++];
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++)
			printf("%c", v[i][j]);
		printf("\n");
	}
	return 0;
}
