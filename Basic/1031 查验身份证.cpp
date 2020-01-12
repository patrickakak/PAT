#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	char z2m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int wt[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int j, sum = 0;
		for (j = 0; j < 17; j++) {
			if (!isdigit(s[j])) break;
			sum += wt[j] * (s[j] - '0');
		}
		int z = sum % 11;
		if (j < 17 || z2m[z] != s[17]) cout << s << endl;
		else cnt++;
	}
	if (cnt == n) cout << "All passed";
	return 0;
}
