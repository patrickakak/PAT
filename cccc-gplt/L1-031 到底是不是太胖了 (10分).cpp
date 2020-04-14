#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, h, w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h >> w;
		double sw = (h-100)*0.9*2;
		if (fabs(w-sw) < sw*0.1)
			cout << "You are wan mei!" << endl;
		else {
			if (w > sw) cout << "You are tai pang le!" << endl;
			else cout << "You are tai shou le!" << endl;
		}
	}
	return 0;
}
