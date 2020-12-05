#include <iostream>
using namespace std;
int main() {
	int m;
	cin >> m;
	string id, in, out, unlock, lock, early = "24:00:00", late = "00:00:00";
	for (int i = 0; i < m; i++) {
		cin >> id >> in >> out;
		if (early > in) {
			early = in;
			unlock = id;
		}
		if (late < out) {
			late = out;
			lock = id;
		}
	}
	cout << unlock << ' ' << lock;
	return 0;
}
