#include <iostream>
using namespace std;
int main() {
	double wt, ht;
	cin >> wt >> ht;
	double ans = wt / (ht*ht);
	printf("%.1f\n", ans);
	if (ans > 25.0) cout << "PANG";
	else cout << "Hai Xing";
	return 0;
}
