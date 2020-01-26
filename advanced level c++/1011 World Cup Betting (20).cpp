#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s = "WTL";
	double profit = 1, a[3] = {0};
	for (int i = 0; i < 3; i++) {
		cin >> a[0] >> a[1] >> a[2];
		int p = max_element(a, a + 3) - a;
		if (i != 0) cout << ' ';
		cout << s[p];
		profit *= a[p];
	}
	printf(" %.2f", 2 * (profit * .65 - 1));
	return 0;
}
