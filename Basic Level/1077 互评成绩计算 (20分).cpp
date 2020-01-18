#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int g2, g1 = 0, cnt = -2, tmp, max = -1, min = m + 1;
		cin >> g2;
		for (int j = 0; j < n-1; j++) {
			cin >> tmp;
			if (tmp >= 0 && tmp <= m) {
				if (tmp > max) max = tmp;
				if (tmp < min) min = tmp;
				g1 += tmp;
				cnt++;
			}
		}
		cout << (int)round((1.0 * (g1-min-max)/cnt + g2) / 2) << endl;
	}
	return 0;
}
