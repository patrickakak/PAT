#include <iostream>
using namespace std;
int main() {
	int n, num, a[6];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a[0] = num / 100000;
		a[1] = num%100000 / 10000;
		a[2] = num%10000 / 1000;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < 3; i++) sum1 += a[i];
		a[3] = num%1000 / 100;
		a[4] = num%100 / 10;
		a[5] = num%10;
		for (int i = 3; i <= 5; i++) sum2 += a[i];
		if (sum1 == sum2) cout << "You are lucky!" << endl;
		else cout << "Wish you good luck." << endl;
	}
	return 0;
}
