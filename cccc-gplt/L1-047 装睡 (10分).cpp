#include <iostream>
using namespace std;
int main() {
	int n, freq, impul;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> freq >> impul;
		if (freq < 15 || freq > 20 || impul < 50 || impul > 70)
			cout << s << endl;
	}
	return 0;
}
