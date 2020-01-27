#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int first = 0, len = 0, maxn = sqrt(n) + 1;
	for (int i = 2; i <= maxn; i++) {
		int j, fac = 1;
		for (j = i; j <= maxn; j++) {
			fac *= j;
			if (n % fac != 0) break;
		}
		if (j - i > len) {
			len = j - i;
			first = i;
		}
	}
	if (first == 0) cout << 1 << endl << n;
	else {
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			cout << first + i;
			if (i != len - 1) cout << '*';
		}
	}
	return 0;
}
