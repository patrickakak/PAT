#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b, d;
	cin >> a >> b >> d;
	int sum = a + b;
	vector<int> v;
	do {
		int r = sum % d;
		sum /= d;
		v.push_back(r);
	} while (sum != 0);
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
	return 0;
}
