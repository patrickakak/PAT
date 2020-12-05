#include <iostream>
#include <vector>
using namespace std;
int main() {
	int ra, ca, rb, cb;
	cin >> ra >> ca;
	vector<vector<int>> m1(ra, vector<int>(ca));
	for (int i = 0; i < ra; i++)
		for (int j = 0; j < ca; j++)
			scanf("%d", &m1[i][j]);
	cin >> rb >> cb;
	if (ca != rb) {
		printf("Error: %d != %d\n", ca, rb);
		return 0;
	}
	vector<vector<int>> m2(rb, vector<int>(cb)), m(ra, vector<int>(cb));
	for (int i = 0; i < rb; i++)
		for (int j = 0; j < cb; j++)
			scanf("%d", &m2[i][j]);
	printf("%d %d\n", ra, cb);
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			for (int k = 0; k < ca; k++)
				m[i][j] += m1[i][k] * m2[k][j];
			if (j != 0) printf(" ");
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
