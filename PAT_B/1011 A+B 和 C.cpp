#include <iostream>
using namespace std;
int main()
{
	long long int t, a, b, c;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		cout << "Case #" << i+1 << ": " << (a + b > c ? "true" : "false") << endl;
	}
	return 0;
}
