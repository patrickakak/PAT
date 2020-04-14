#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	char c;
	cin >> n >> c;
	int row = round(1.0*n/2);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}
