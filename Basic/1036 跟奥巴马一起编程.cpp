#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	char c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) cout << c;
	cout << endl;
	int row = round(1.0 * n / 2);
	for (int i = 0; i < row-2; i++) {
		cout << c;
		for (int i = 0; i < n-2; i++) cout << ' ';
		cout << c << endl;
	}
	for (int i = 0; i < n; i++) cout << c;
	return 0;
}
