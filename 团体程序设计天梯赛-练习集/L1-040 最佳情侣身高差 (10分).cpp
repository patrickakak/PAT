#include <iostream>
using namespace std;
int main() {
	int n;
	char c;
	double h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> h;
		if (c == 'M') printf("%.2f\n", h/1.09);
		else printf("%.2f\n", h*1.09);
	}
	return 0;
}
